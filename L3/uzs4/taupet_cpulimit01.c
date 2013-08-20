* Tautvydas Petkus IF- 1/9 taupet */
/* Failas: taupet_limits01.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>

int tp_change_filelimit( int nslimit, int nhlimit );
int tp_test_filelimit( const char *fn );

int tp_change_filelimit( int nslimit, int nhlimit ){
   struct rlimit rl;
   struct rlimit rlp;
   getrlimit( RLIMIT_CPU, &rl );
   printf( "RLIMIT_CPU %ld (soft) %ld (hard)\n", rl.rlim_cur, rl.rlim_max );
   rl.rlim_cur = nslimit;
   rl.rlim_max = nhlimit;
   rlp.rlim_cur = 0;
   setrlimit( RLIMIT_CPU, &rl );
   setrlimit( RLIMIT_CORE, &rlp);
   getrlimit( RLIMIT_CPU, &rl );
   getrlimit( RLIMIT_CORE, &rlp);
   printf( "RLIMIT_CPU %ld (soft) %ld (hard)\n", rl.rlim_cur, rl.rlim_max );
   printf( "RLIMIT_CORE %ld", rlp.rlim_cur);
   return 1;
}

int tp_test_filelimit( const char *fn ){
   int i = 1;
   int j = 0;
   while (i != 0){
        j++;
   }
        int n;
        for( n = 0; -1 != open( fn, O_RDONLY ); n++ );
        printf( "Can open %d files\n", n );
        printf( "j= %d\n", j);
   return 1;
}  
   
int main( int argc, char *argv[] ){
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
         tp_change_filelimit( 5, 10); 
         tp_test_filelimit( argv[0] );
   return 0;
}


