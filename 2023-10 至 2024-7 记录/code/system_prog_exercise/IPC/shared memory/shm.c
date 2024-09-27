#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(void)
{
    // create a key
    key_t key = ftok("sham", 'a');
    // create a space
    int id = shmget(key, 1024, 0666 | IPC_CREAT);
    // getting a pointer to the segment
    char *data;
    data = shmat(id, (void *)0, 0);
    if (data == (void *)-1)
    {
        perror("shmat");
        exit(1);
    }

    // write something to the space
    fgets(data, 1024, stdin);
    // read from the space
    printf("The data is: %s\n", data);
    // detach from shared memory
    int ret = shmdt(data);
    if (ret == -1)
    {
        perror("shmdt failed.");
        exit(1);
    }
    // destroy the shared memory
    shmctl(id, IPC_RMID, NULL);
}