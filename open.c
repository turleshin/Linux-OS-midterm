#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

int fd = open("./1mb.txt", O_RDWR);

char buf[1023385];
buf[1023284]='\0';
size_t byte_rd = read(fd,buf,1023385);
printf("%s\n",buf);
return 0;
}

