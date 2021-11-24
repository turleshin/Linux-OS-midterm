#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/file.h>
#include <string.h> 
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char **argv){

    int sfd, dfd;
    char *src, *dest;
    size_t filesize;

    /* SOURCE */
    sfd = open(argv[1], O_RDONLY);
    filesize = lseek(sfd, 0, SEEK_END);

    src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, sfd, 0);

    /* DESTINATION */
    dfd = open(argv[2], O_RDWR | O_CREAT, 0666);

    ftruncate(dfd, filesize);

    dest = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);

    /* COPY */

    memcpy(dest, src, filesize);

    munmap(src, filesize);
    munmap(dest, filesize);

    close(sfd);
    close(dfd);

    return 0;
}
