/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_exit01.c */

#include <stdio.h>
#include <stdlib.h>

void tp_exit1();
void tp_exit2();
void tp_exit3();
int tp_atexit(int arg);

void tp_exit1()
{
   printf( "EXIT function 1 \n");
}

void tp_exit2()
{
   printf( "EXIT function 2 \n");
}

void tp_exit3()
{
   printf( "EXIT function 3 \n");
}

int tp_atexit(int arg)
{
   atexit(tp_exit1);
   atexit(tp_exit2);
   atexit(tp_exit3);
   printf( "Pagr. funkcija, argv[1] = %d\n", arg);
   if (arg == 1)
   {
        printf( "_Exit(0) \n");
        _Exit(0);
   }
   if (arg == 2)
   {
        printf( "exit(0) \n");
        exit(0);
   } 
   if (arg == 3)
   {
        printf( "abort() \n");
        abort();
   }
   printf( "return 0 \n");
   return 0;
}  
   
int main( int argc, char * argv[] ){ 
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   tp_atexit(atoi(argv[1]));
   return 0;
}

