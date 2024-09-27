#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    char s[200];

    // craete the fifo
    mknod("myfifo", S_IFIFO | 0644, 0);

    // open the fifo
    int fd = open("myfifo", O_WRONLY);

    // write something to it
    while (gets(s), !feof(stdin))
    {
        int w_count = write(fd, s, sizeof(s));
        if (w_count == -1)
        {
            perror("write");
            exit(1);
        }
        else
        {
            printf("write %d bytes to fifo\n", w_count);
        }
    }
    return 0;
}