/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_readdir01.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

int tp_test_getcwd();
void tp_test_runDir(const char *name);

void tp_test_runDir(const char *name){
   DIR *dir;
   struct dirent *DirEntry;
   dir = opendir( name);
   while(DirEntry = readdir(dir))
   {
      printf("%i", DirEntry->d_ino);
      printf(" %s\n", DirEntry->d_name);
   }
   closedir(dir);
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
   return 0;
}

