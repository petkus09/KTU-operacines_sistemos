
/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_seek01.c */

#include <stdio.h>
#include <aio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int vp_test();

int vp_test(){
   return 0;
}

int main( int argc, char * argv[] ){
   int d;
   int rv;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   d = creat( argv[1], 0777);
   lseek(d, 1048576, SEEK_SET);
   write(d, &d, 1);
   rv = close(d);
   return 0;
