#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main ( void ) {
    pid_t pid;
    pid_t pid2 = -5;

    printf("Kuriamas vaiko procesas...\n");
    pid = fork();
    if ( pid == -1 ) {
        perror("Nepavyko sukurti vaiko1 proceso!");
        exit(1);
    }
    if (pid != 0)
    {                   /* Kuria vaiko procesa  */
       pid2 = fork();
    }
    if (pid2 == -1) {
        perror("Nepavyko sukurti vaiko2 proceso!");
        exit(1);
    }
    if ( pid2 == 0) {
        /* Vaiko2 proceso PRADZIA */
        printf("1) ------------------------------\n");
        printf("2) ::::::::Vaiko2 procesas::::::::\n");
        system("ps");
        printf("3) Dabartinio proceso ID (PID): %ld\n", getpid());
        printf("4) Tevo proceso ID (PPID)     : %ld\n", getppid());
        printf("5) Kintamasis pid           : %ld\n", pid2);
        printf("6) *** VAIKO2 PROCESO PABAIGA ***\n");
        exit(12);
        /* Vaiko2 proceso PABAIGA  */
    }
    if ( pid == 0 && pid2 != 0) {
        int status;
        /* Vaiko1 proceso PRADZIA */
        printf("7) ------------------------------\n");
        printf("8) ::::::::Vaiko1 procesas::::::::\n");
        printf("9) Dabartinio proceso ID (PID): %ld\n", getpid());
        printf("10) Tevo proceso ID (PPID)     : %ld\n", getppid());
        printf("11) Kintamasis pid           : %ld\n", pid);
        printf("12) *** VAIKO1 PROCESO PABAIGA ***\n");
        exit(20); 
        /* Vaiko1 proceso PABAIGA  */
    } else {                            /* pid > 0 */  
        /* Tevo proceso PRADZIA */

        int   status = 0;               /* Vaiko grazinta busena per exit() */
        pid_t pidwait = 0;
        /* Kas atsitiks jei uzkomentuosime wait() eilute? Isbandykite! */
        pidwait = wait(&status);        /* Tevas laukia kol uzsibaigs jo vaiko procesas */
        wait(&status);
        printf("13) ::::::::Tevo procesas::::::::\n");
        printf("14) Tevo procesas islauke kol vaiko procesas baige darba.\n");
        printf("15) Dabartinio proceso ID (PID): %ld\n", getpid());
        printf("16) Tevo proceso ID (PID)     : %ld\n", getppid());
        printf("17) Kintamasis pid          : %ld\n", pid);
       printf("17) Kintamasis pid2          : %ld\n", pid2);
        printf("18) Kintamasis pidwait      : %ld\n", pidwait);
        printf("19) Kintamasis status       : %d\n", WEXITSTATUS(status));
        printf("20) *** TEVO PROCESO PABAIGA ***\n");
        exit(0);
        /* Tevo proceso PABAIGA */
    }   
    return 0;
}

