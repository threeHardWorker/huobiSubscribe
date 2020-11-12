# huobiSubscribe
sudo apt-get install libboost-all-dev -y
sudo apt-get install git -y
sudo apt-get install cmake -y
sudo apt-get install rapidjson-dev -y

git clone https://github.com/zaphoyd/websocketpp
cd websocketpp/
mkdir build && cd build 
cmake ..
make
sudo make install

测试:
cd ../../websocketpp/examples/echo_server
g++ -o echo_server echo_server.cpp -lboost_system -lboost_chrono -lpthread
./echo_server

cd ../../websocketpp/examples/echo_client
g++ -o echo_client echo_client.cpp -lboost_system -lboost_random -lboost_chrono -lpthread
./echo_client


libuv安装
sudo apt install autoconf -y
sudo apt install libtool -y
wget https://github.com/libuv/libuv/archive/v1.x.tar.gz
tar -zxvf v1.x.tar.gz
cd libuv-1.x
sh autogen.sh
./configure
make -j4
sudo make install
sudo ldconfig

安装信息如下：
/bin/mkdir -p '/usr/local/include'
/usr/bin/install -c -m 644 include/uv.h '/usr/local/include'
/bin/mkdir -p '/usr/local/lib/pkgconfig'
/usr/bin/install -c -m 644 libuv.pc '/usr/local/lib/pkgconfig'
/bin/mkdir -p '/usr/local/include/uv'
/usr/bin/install -c -m 644 include/uv/errno.h include/uv/threadpool.h include/uv/version.h include/uv/unix.h include/uv/linux.h '/usr/local/include/uv'
make[1]: Leaving directory '/home/yanqi/websocketpp/examples/echo_client/libuv-1.x'


//libuv demo demo1.c：
mkdir demo
cd demo
cp -r ~/websocketpp/examples/echo_client/libuv-1.x/include ./
vi demo1.c

#include <stdio.h>
#include <stdlib.h>
#include "include/uv.h"

int main() {
    uv_loop_t *loop = (uv_loop_t*)malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    printf("Now quitting.\n");
    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);
    return 0;
}

编译及连接：
#gcc -c demo1.c -o demo1  /usr/local/lib/libuv.so #该方法有问题
gcc demo1.c -L/usr/local/lib/ -luv -o demo1

运行：
./demo1
输出：
Now quitting

下载socket.io
git clone https://github.com/socketio/socket.io-client-cpp.git
cd socket.io-client-cpp/lib
rm rapidjson -rf
git clone https://github.com/Tencent/rapidjson.git
rm websocketpp -rf
git clone https://github.com/zaphoyd/websocketpp.git

cd ../../socket.io-client-cpp
mkdir build && cd build
cmake ..
make

拷贝文件socket.io-client-cpp/build/libsioclient.a
cp -r /home/frank/project/socket.io-client-cpp/lib /home/frank/project/huobiSubscribe/include

