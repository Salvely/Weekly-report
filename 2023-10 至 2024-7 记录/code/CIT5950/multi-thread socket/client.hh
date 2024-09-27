#include <netinet/in.h>
class Client
{
private:
    struct sockaddr_in addr;
    int sock;
    char send_buf[1024];
    char recv_buf[1024];

public:
    Client();
    ~Client();
    int connectToServer();
    void chat();
    void disconnectFromServer();
};