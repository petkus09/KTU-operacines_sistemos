/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_nftw02.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ftw.h>

int kp_ftwinfo(const char *p, const struct stat *st, int fl, struct FTW *fbuf);

int kp_ftwinfo(const char *p, const struct stat *st, int fl, struct FTW *fbuf){
   static int cnt = 0;
   puts( p );
   cnt++;
   return 0;
}

int main( int argc, char * argv[] ){
   int rv;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__  );

   rv = nftw( "/home/taupet", kp_ftwinfo, 20, FTW_PHYS );
   if( rv == -1 ){
      perror( "nftw failed" );
      exit( 1 );
   }
   if( rv != 0 ){
      printf( "ntfw fn function returnd %d != 0 -> nftw finished\n", rv );
   }
   return 0;

}



