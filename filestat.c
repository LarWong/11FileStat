#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <math.h>
#include <string.h>

int main(){

    struct stat fileinfo;
    stat("filestat.c", &fileinfo);

    printf("\nPrinting stat info about this file...\n\n");

    off_t size = fileinfo.st_size;
    char pref = 0;
    long mult = 1;
    char pref_ary[3] = "KMG";
    for (int i = 1; i <= 3; i++){
        if (size >= pow(1000,i)){
            pref = pref_ary[i-1];
            mult = pow(1000,i);
        }
    }

    mode_t mode = fileinfo.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    char * men2 = calloc(sizeof(char), 10);
    strcpy(men2,"rwxrwxrwx");
    for (int i = 0; i<9; i++){
        //printf("%o\n",mode >> i);
        men2[8 - i] = mode >> i & 1 ? men2[8 - i] : '-';
    }

    char * men = calloc(6,sizeof(char));
    pref!=0 ? sprintf(men, "%lld%cB",size/mult,pref) : sprintf(men, "%lldB",size/mult);
    printf("\tFile Size: %s\n",men);
    //printf("\tFile Size: %llu\n",fileinfo.st_size);
    printf("\tFile Permissions(octal): %o\n",fileinfo.st_mode);
    printf("\tFile Permissions(perm_bits): %s\n",men2);
    printf("\tTime of Last Access: %s\n",ctime(&fileinfo.st_atime));

    return 0;
}
