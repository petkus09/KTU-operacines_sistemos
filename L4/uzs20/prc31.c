#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <stdlib.h>

static int gautas_signalas = 0;

void funkcija () {
    gautas_signalas = 1;
}

void funkcija2 () {
    gautas_signalas = 2;
}

int main( void ) {
    pid_t  pid;


    pid = fork();
    if ( pid == -1 ) {
        perror("Klaida! Nepavyko sukurti vaiko.");
        exit   (1);
    }
    if ( pid != 0 ) {
        printf("TEVAS: mano pid = %ld\n", getpid());
        printf("TEVAS: mano vaiko pid = %ld\n", pid);
        kill(pid, SIGUSR1);
        signal(SIGUSR2, funkcija2);
        while(1)
           if (gautas_signalas == 2) {
              kill( pid, SIGTERM );
              printf( "TEVAS: Vaika nuzudziau.\n" );
              wait(NULL);
              sleep(5);
              printf( "TEVAS: baigiu darba.\n" );
              return 0;
           }
    } else {
        printf( "VAIKAS: mano PID = %ld\n", getpid() );
        signal(SIGUSR1, funkcija);
        while(1)
            if ( gautas_signalas == 1 ) {
                printf( "VAIKAS: signala gavau!\n" );
                system("who");
                kill(getppid(), SIGUSR2);
                gautas_signalas = 0;
                printf( "VAIKAS: baigiu darba.\n" );
                return 0;
            }
    }
}
