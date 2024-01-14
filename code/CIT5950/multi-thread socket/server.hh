#include <netinet/in.h>
#include <queue>
#include <utility>
#include <mutex>
#include <pthread.h>

class Server
{
private:
    struct sockaddr_in addr;
    char recv_buf[1024];
    char send_buf[1024];
    std::queue<int> conn_queue;
    int sock;

    pthread_mutex_t mutex;
    pthread_cond_t cond;

public:
    Server();
    ~Server();
    int acceptConnection();
    void chat();
    void disconnect();
};