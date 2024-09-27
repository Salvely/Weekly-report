#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    struct flock fl =
        {
            .l_type = F_WRLCK,
            .l_whence = SEEK_SET,
            .l_start = 0,
            .l_len = 0,
        };
    int fd;
    fd = open("filename", O_WRONLY);

    fcntl(fd, F_SETLKW, &fl);

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
}