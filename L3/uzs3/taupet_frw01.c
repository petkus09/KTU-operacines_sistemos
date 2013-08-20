/* Tautvydas Petkus IF-1/9 taupet */
/* Failas: taupet_frw01.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void tp_action(const char *readf, const char *writef, int dydis);

void tp_action(const char *readf, const char *writef, int dydis){
        printf ("%d\n", dydis);
        FILE *fp;
        char buf[dydis];
        fp = fopen(readf, "r");
        fread(buf, sizeof(buf), 1, fp);
        fclose(fp);
        fp = fopen(writef, "w");
        fwrite(buf, sizeof(buf), 1, fp);
        fclose(fp);
}

int main( int argc, char * argv[] ){
   printf( "(C) 2013 Tautvydas Petkus, %s\n", __FILE__ );
   tp_action(argv[1], argv[2], (int)argv[3]);
   return 0;
}


