/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_mmap02.c */


#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>

#define SIZE 1048576

int tp_test_openw(const char *name);
int tp_test_close(int fd);
void* tp_test_mmapw( int d, int size );
void* tp_test_mmapwRead(int d, int size );
int tp_test_munamp( void *a, int size );
int tp_test_usemaped( void *a, int size );

int tp_test_openw(const char *name){
   int dskr;
   dskr = open( name, O_RDWR | O_CREAT | O_EXCL, 0640 );
   if( dskr == -1 ){
      perror( name );
      exit( 255 );
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

void* tp_test_mmapwRead( int d, int size ){
   void *a = NULL;
   lseek( d, size - 1, SEEK_SET );
   write( d, &d , 1 );  /* iraso bile ka i failo gala */
   a = mmap( NULL, size, PROT_READ, MAP_SHARED, d, 0 );
   if( a == MAP_FAILED ){
      perror( "mmap failed" );
      abort();
   }
   return a;
}

void* tp_test_mmapw( int d, int size ){
   void *a = NULL;
   lseek( d, size - 1, SEEK_SET );
   write( d, &d , 1 );  /* iraso bile ka i failo gala */
   a = mmap( NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, d, 0 );
   if( a == MAP_FAILED ){
      perror( "mmap failed" );
      abort();
   }
   return a;
}


int tp_test_munamp( void *a, int size ){
   int rv;
   rv = munmap( a, size );
   if( rv != 0 ){
      puts( "munmap failed" );
      abort();
   }
   return 1;
}

int tp_test_usemaped( void *a, int size ){
   memset( a, 0xF0, size );
   return 1;
}

int main( int argc, char * argv[] ){
   int d1;
   int d2;
   struct stat st;
   void *a1 = NULL;
   void *a2 = NULL;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   if( argc != 2 ){
      printf( "Naudojimas:\n %s failas\n", argv[0] );
      exit( 255 );
   }
   d1 = tp_test_openw( argv[1] );
   d2 = tp_test_openw( argv[2] );
   a1 = tp_test_mmapwRead( d1, SIZE );
   a2 = tp_test_mmapw(d2, SIZE);
   fstat(d1, &st);
   memcpy(a2, a1, sizeof(st));
   tp_test_munamp( a1, SIZE );
   tp_test_munamp( a2, SIZE );
   tp_test_close( d1 );
   tp_test_close( d2 );
   return 0;
}

