/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_clock02.c */

#include <stdio.h>
#include <time.h>
#define GMT (+3)

int tp_test_clock();

int tp_test_clock(){
   time_t timer;
   struct tm * timeinfo;
   struct tm * ptm;
   time(&timer);
   timeinfo = localtime(&timer);
   ptm = gmtime(&timer);
   printf( "time() =%.lld\n asctime(localtime())=%s gmtime()=%2d:%02d\n asctime(gmtime())=%s\n", (long long) timer, asctime(timeinfo), (ptm->tm_hour + GMT)%24, ptm->tm$
   return 1;
}

int main( int argc, char * argv[] ){
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   tp_test_clock();
   return 0;
}


