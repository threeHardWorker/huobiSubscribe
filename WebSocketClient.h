#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H
#include <string>
#include <sio_client.h>

using namespace std;
using namespace sio;

class WebSocketClient
{
public:
    WebSocketClient(const string &url);
    ~WebSocketClient();

private:
    void onConnected(string const& nsp);
    void onClosed(client::close_reason const& reason);
    void onFailed();

private:
    std::unique_ptr<client> _io = nullptr;
};

#endif // WEBSOCKETCLIENT_H
