SRC = $(wildcard ./*.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
TARGET = main


# 必须在命令中使用自动变量
# $@ 表示目标
# $^ 所有的依赖
# $< 第一个依赖
$(TARGET):${OBJS}
# - 此命令错处，make 也会继续执行后续的命令
	-gcc $^ -o $@

# 模式匹配 所有.o都依赖对应的.c
# 将所有的.c 生成对应的.o
*.o:*.c
	# @不显示命令本身，只显示结果
	@gcc -c $< -o $@


# 声明clean为伪目标，伪目标不去判断目标文件是否存在或者已经更新
.PHONY:clean
clean:
	rm -rf ${OBJS} $(TARGET)
