/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_pathconf.c */

#include <stdio.h>
#include <unistd.h>

int vp_test();

int vp_test(){
   return 0;
}

int main( int argc, char * argv[] ){
   long a1 = pathconf( __FILE__, _PC_NAME_MAX );
   long a2 = pathconf( __FILE__, _PC_PATH_MAX );
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   printf("Max Vardas : %d\n", a1 );
   printf("Max Kelias : %d\n", a2 );
   return 0;
}

