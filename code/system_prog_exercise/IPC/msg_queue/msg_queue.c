#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <unistd.h>

// define the message struct
struct msgbuf
{
    long mtype;
    char mtext[20];
};

int main(void)
{
    // create the key
    key_t key = ftok("my_queue", 'b');
    // create the queue
    int qid = msgget(key, 0666 | IPC_CREAT);

    // define the message
    struct msgbuf buf;
    // fill in the message
    buf.mtype = 2;
    strcpy(buf.mtext, "I love you!");
    size_t size = sizeof(buf.mtext);

    pid_t child = fork();
    if (child == 0)
    {
        // receive the message
        msgrcv(qid, &buf, size, 2, 0);
        fprintf(stdout, "receive message from %d: %s\n", qid, buf.mtext);
    }
    // send a message
    msgsnd(qid, &buf, size, 0);
    // destroy the message queue
    msgctl(qid, IPC_RMID, NULL);
    return 0;
}