/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_libtest02.c */

#include <stdio.h>
#include "taupet_testlib02.h"

int main( int argc, char * argv[] ){
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   tp_test_getcwd();
   cwd = tp_test_getcwd();
   return 0;
}



