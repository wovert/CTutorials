/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/19
 */

#ifndef LIBREIMSERVER_RECEIVE_H
#define LIBREIMSERVER_RECEIVE_H

#include "event2/event.h"
#include "event2/buffer.h"
#include "event2/bufferevent.h"
void receive_buff(struct bufferevent *bev,char *buff);

#endif //LIBREIMSERVER_RECEIVE_H
