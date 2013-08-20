/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_getcwd02.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int tp_test_getcwd();
int tp_test_open(const char *name);
int tp_test_close(int fd);

int tp_test_open(const char *name){
   int dskr;
   dskr = open( name, O_RDONLY );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   printf( "dskr = %d\n", dskr );
   return dskr;
}

int tp_test_close(int fd){
   int rv;
   rv = close( fd );
   if( rv != 0 ) perror ( "close() failed" );
   else puts( "closed" );
   return rv;
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
   int dopen;
   int dclose;
   char *directory = "/tmp";
   int ret;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__  );
   dcwd = tp_test_getcwd();
   dopen = tp_test_open(getcwd( NULL, pathconf(".",_PC_PATH_MAX)));
   ret = chdir(directory);
   tp_test_getcwd();
   fchdir(dopen);
   dclose = tp_test_close(dopen);
   tp_test_getcwd();
   return 0;
}
