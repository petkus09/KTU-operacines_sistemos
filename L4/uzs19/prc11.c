#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main ( void ) {
    pid_t pid;

   // system("ps");

    printf("Kuriamas vaiko procesas...\n");
    pid = fork();                       /* Kuria vaiko procesa  */
    if ( pid == -1 ) {
        perror("Nepavyko sukurti vaiko proceso!");
        exit(1);
    }
    if ( pid == 0 ) {
        /* Vaiko proceso PRADZIA */
        printf("1) ------------------------------\n");
        printf("2) ::::::::Vaiko procesas::::::::\n");
        //system("ps");
        printf("3) Dabartinio proceso ID (PID): %ld\n", getpid());
        printf("4) Tevo proceso ID (PPID)     : %ld\n", getppid());
        printf("5) Kintamasis pid           : %ld\n", pid);
        printf("6) *** VAIKO PROCESO PABAIGA ***\n");
        /* Vaiko proceso PABAIGA  */
        pid_t pid2;
        //system ("ps2");
        printf("Kuriamas vaikaicio procesas...\n");
        pid2 = fork();
        if (pid2 == 0)
        {
              /* Vaikaicio proceso PRADZIA */
                  printf("7) ------------------------------\n");
                 printf("8) ::::::::Vaikaicio procesas::::::::\n");
                system("ps -f");
                printf("9) Dabartinio proceso ID (PID): %ld\n", getpid());
                printf("10) Tevo proceso ID (PPID)     : %ld\n", getppid());
                printf("11) Kintamasis pid2           : %ld\n", pid2);
               printf("12) *** VAIKAICIO PROCESO PABAIGA ***\n");
                exit(20);
                /* Vaikaicio proceso PABAIGA  */
        }
        exit(20);
     }  
       else{                            /* pid > 0 */
        /* Tevo proceso PRADZIA */

        int   status = 0;               /* Vaiko grazinta busena per exit() */
        pid_t pidwait = 0;
        /* Kas atsitiks jei uzkomentuosime wait() eilute? Isbandykite! */
        pidwait = wait(&status);        /* Tevas laukia kol uzsibaigs jo vaiko procesas */

        printf("13) ::::::::Tevo procesas::::::::\n");
        //system("ps");
        printf("14) Tevo procesas islauke kol vaiko procesas baige darba.\n");
        printf("15) Dabartinio proceso ID (PID): %ld\n", getpid());
        printf("16) Tevo proceso ID (PID)     : %ld\n", getppid());
        printf("17) Kintamasis pid          : %ld\n", pid);
       printf("18) Kintamasis pidwait      : %ld\n", pidwait);
        printf("19) Kintamasis status       : %d\n", WEXITSTATUS(status));
        printf("20) *** TEVO PROCESO PABAIGA ***\n");
        exit(0);
        /* Tevo proceso PABAIGA */
    }  
    return 0;                           
}


