/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_nice01.c */

#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <sys/times.h>

int tp_time(int val);

int tp_time(int val)
{
   int niceval = nice(val);
   printf( "Priority nice: %d\n",  niceval);
   clock_t start, end, diff;
   int i;
   start = clock();
   for (i = 0; i< 0x7AFFFFFF; i++);
   end = clock();
   diff = end - start;
   printf( "CLOCKS_PER_SEC = %ld\n start=%ld\n end=%ld\n diff=%ld, diff(s)= %f\n", CLOCKS_PER_SEC, start, end, diff, (double)diff / CLOCKS_PER_SEC);
   return 1;
}

int main( int argc, char * argv[] ){
   clock_t start;
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   tp_time(atoi(argv[1]));
   clock_t end;
   unsigned long millis = (end - start) / CLOCKS_PER_SEC;
   printf( "CPU TIME: %llu\n", millis);
   return 0;
}

