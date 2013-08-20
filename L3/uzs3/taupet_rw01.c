/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_rw01.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int tp_test_open(const char *name, int flag);
void tp_writting(int readf, int writef, int dydis);

int tp_test_open(const char *name, int flag){
   int dskr;
   dskr = open( name, flag );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   printf( "dskr = %d\n", dskr );
   return dskr;
}

void tp_writting(int readf, int writef, int dydis){
        char buf[1000];
        size_t nbytes = dydis;
        size_t nbytesWrite;
        ssize_t bytes_read;
        nbytes = sizeof(buf);
        bytes_read = read(readf, buf, nbytes);
        nbytesWrite = write(writef, buf, nbytes);
}

int main( int argc, char * argv[] ){
   int dopenr;
   int dopenw;
   struct stat st;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   dopenr = tp_test_open(argv[1], O_RDONLY );
   dopenw = tp_test_open(argv[2], O_WRONLY );
   tp_writting( dopenr, dopenw, (int)argv[3]);
   close(dopenr);
   close(dopenw);
   return 0;
}
