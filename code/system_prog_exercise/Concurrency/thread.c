#include <pthread.h>
#include <stdio.h>

static void *greet(void *data)
{
    int id = *((int *)data);
    printf("Hello, thread %d!\n", id);
    pthread_exit(0);
}

int main(void)
{
    pthread_t th_arr[10];
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&th_arr[i], NULL, greet, (void *)&i);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(th_arr[i], NULL);
    }
    return 0;
}