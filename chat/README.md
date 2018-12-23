# 聊天程序

## 安装libuv库 for Mac

`$ brew install --HEAD libuv`


## Setup libuv for Ubuntu

``` sh
$ sh autogen.sh
$ ./configure
$ make
$ make check
$ make install

正常情况下你会遇到几个问题，解决方式如下：
sudo apt-get install autoconf autogen
sudo apt-get install libtool

```

## 编译程序




`$ gcc -g -Wall filename.c -o filename -luv`