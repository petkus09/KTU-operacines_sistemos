#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[] ) {
    pid_t pid;
    printf("Kuriamas vaiko procesas...\n");
    pid = fork();                       /* Kuria vaiko procesa  */
    if ( pid == -1 ) {
        perror("Nepavyko sukurti vaiko proceso!");
        exit(1);
    }
    if ( pid == 0 ) {
        sleep(1);
        /* Vaiko proceso PRADZIA */
        printf("3) ::::::::Vaiko procesas::::::::\n");
        char str[512];
        memset(str, '\0', sizeof(512));
        sprintf(str, "./pap2 %s", argv[2]);
        system(str);
        printf(") *** VAIKO PROCESO PABAIGA ***\n");
        exit(4);
        /* Vaiko proceso PABAIGA  */
    } else {                            /* pid > 0 */
        /* Tevo proceso PRADZIA */
        printf("1) ::::::::Tevo procesas::::::::\n");
        char str[512];
        memset(str, '\0', sizeof(512));
        sprintf(str, "./pap1 %s %s", argv[1], argv[2]);
        system(str);
        printf("2) *** TEVO PROCESO PABAIGA ***\n");
        exit(0);
        /* Tevo proceso PABAIGA */
    }
    return 0;
}

