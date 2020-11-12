#include "WebSocketClient.h"
#include <functional>
#include <sio_socket.h>

WebSocketClient::WebSocketClient(const string &url)
    : _io(new client())
{
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    using std::placeholders::_4;

    socket::ptr sock = _io->socket();
    _io->set_socket_open_listener(std::bind(&WebSocketClient::onConnected, this, std::placeholders::_1));
    _io->set_close_listener(std::bind(&WebSocketClient::onClosed, this, _1));
    _io->set_fail_listener(std::bind(&WebSocketClient::onFailed, this));
    _io->connect(url);
}

WebSocketClient::~WebSocketClient()
{
    _io->socket()->off_all();
    _io->socket()->off_error();
    printf("end %p\n", this);
}

void WebSocketClient::onConnected(std::string const& nsp)
{
    printf("onConnected:%s\n", nsp.c_str());
}

void WebSocketClient::onClosed(client::close_reason const& reason)
{
    printf("onClosed:%d\n", reason);
}

void WebSocketClient::onFailed()
{
    printf("onFailed\n");
}
