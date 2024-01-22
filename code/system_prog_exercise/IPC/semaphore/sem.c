#include <sys/ipc.h>
#include <sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    ushort *array;
};

int main(void)
{
    // create a key
    key_t key = ftok("sem", 'b');

    // create a semaphore
    int sem_id = semget(key, 10, 0666 | IPC_CREAT);

    // initialize the semaphore
    // destroy the semaphore
    int ret = semctl(sem_id, 0, IPC_RMID);
}