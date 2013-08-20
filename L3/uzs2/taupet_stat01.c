/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_stat01.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

int tp_test_getcwd();
void tp_test_runStat(const char *name);

void tp_test_runStat(const char *name){
  int st;
  struct stat fileStat;
  st = stat(name, &fileStat);
  printf("Failas: %s\n", name);
  printf("Failo dydis: \t\t%d bytes\n", fileStat.st_size);
  printf("Link skaicius: \t%d\n", fileStat.st_nlink);
  printf("Failo inode: \t\t%d\n", fileStat.st_ino);
}

int tp_test_getcwd(){
   char *cwd;
   cwd = getcwd(NULL, pathconf(".",_PC_PATH_MAX));
   puts( cwd );
   free( cwd );
   return 1;
}

int main( int argc, char * argv[] ){
   int dcwd;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__  );
   dcwd = tp_test_getcwd();
   tp_test_runStat(argv[1]);
   return 0;
}

