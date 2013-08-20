/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_dynload02.c */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int *pd;

int main( int argc, char * argv[] ){
   void *dl;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   return 0;
   dl = dlopen( argv[1], RTLD_LAZY | RTLD_LOCAL );
   pd = dlsym( dl, argv[1]);
   dlclose(dl);
}

