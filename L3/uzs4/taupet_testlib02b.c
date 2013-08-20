/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_testlib02b.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <errno.h>
#include "taupet_testlib02.h"

int tp_test_getcwd();
void tp_test_runStat(const char *name);

void tp_test_runStat(const char *name){
  int st;
  int stvfs;
  struct stat fileStat;
  struct statvfs fileStatvfs;
  st = stat(name, &fileStat);
  stvfs = statvfs(name, &fileStatvfs);
  printf("Failas: %s\n", name);
  printf("Failo dydis: \t\t%d bytes\n", fileStat.st_size);
  printf("Link skaicius: \t%d\n", fileStat.st_nlink);
  printf("Failo inode: \t\t%d\n", fileStat.st_ino);
  printf("Failo bloku dydis: %d\n", fileStatvfs.f_bsize);
  printf("Laisvu bloku skaicius: %d\n", fileStatvfs.f_bfree);
  printf("Laisvi blokai neprivilegijuotiems naudotojams: %d\n", fileStatvfs.f_bavail);
  printf("i-node'ai: %d\n", fileStatvfs.f_files);
  printf("Failo sistemos ID: %l\n", fileStatvfs.f_fsid);
  printf("Veliaveles: %d\n", fileStatvfs.f_flag);
  printf("Didziausias failo vardo ilgis: %d\n", fileStatvfs.f_namemax);
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
  

