/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_misc01.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <errno.h>

int tp_test_getcwd();
void tp_test_mkdir(const char *name);

void tp_test_mkdir(const char *name){
  int dirC;
  dirC = mkdir(name, S_IRUSR);
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
   tp_test_mkdir(argv[1]);
   return 0;
}
