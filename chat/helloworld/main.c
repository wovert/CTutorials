#include <stdio.h>
#include <string.h>
#include <uv.h>

uv_tty_t g_tty;
uv_timer_t g_tick;
int g_width, g_height, g_pos;

static void __update(uv_timer_t* req)
{
    uv_write_t wreq;
    char data[64];
    const char* msg = "    Hello TTY    ";
    uv_buf_t buf;   
    buf.base = data;
    buf.len = sprintf(data, "\033[2J\033[H\033[%dB\033[%luC\033[42;37m%s",
                            g_pos, (g_width - strlen(msg))/2, msg); 
    uv_write(&wreq, (uv_stream_t*)&g_tty, &buf, 1, NULL);
    
    if(++g_pos > g_height){
        uv_tty_reset_mode();
        uv_timer_stop(&g_tick);
    }   
}

// 主函数检测
int main(void)
{
    uv_loop_t* loop = uv_default_loop();
    
    uv_tty_init(loop, &g_tty, 1, 0); 
    uv_tty_set_mode(&g_tty, 0); 
    
    if(uv_tty_get_winsize(&g_tty, &g_width, &g_height)){
        puts("Could not get TTY information");
        uv_tty_reset_mode();
        return 1;
    }   
    
    printf("Width %d, height %d\n", g_width, g_height);
    uv_timer_init(loop, &g_tick);
    uv_timer_start(&g_tick, __update, 200, 200);    

    return uv_run(loop, UV_RUN_DEFAULT);
}