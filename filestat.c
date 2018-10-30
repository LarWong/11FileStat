#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main(){

    struct stat fileinfo;
    stat("filestat.c", &fileinfo);

    printf("\nPrinting stat info about this file...\n\n");

    printf("\tFile Size: %llu\n",fileinfo.st_size);
    printf("\tFile Permissions(octal): %o\n",fileinfo.st_mode);
    printf("\tTime of Last Access: %s\n",ctime(&fileinfo.st_atime));

    return 0;
}
