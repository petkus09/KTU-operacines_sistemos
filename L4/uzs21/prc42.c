 #include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

static int gautas_signalas = 0;
#define BUFLEN  100

void funkcija () {
    gautas_signalas = 1;
}

int main( void ) {
    pid_t  pid;
    int      fd[2];
    char buf[BUFLEN];
    if ( pipe ( fd ) == -1 )
      { fprintf ( stderr, "Nepavyko sukurti programinio kanalo !\n" );
        exit    ( 1 );
      }

    pid = fork();
    if ( pid == -1 ) {
        perror("Klaida! Nepavyko sukurti vaiko.");
        exit   (1);
    }
    if ( pid != 0 ) {
        printf("TEVAS: mano pid = %ld\n", getpid());
        printf("Iveskite pavarde: \n");
        scanf ("%s", buf);
        printf ("%s\n", buf);
        write ( fd[1], &buf, sizeof(buf) );
        kill(pid, SIGUSR1);
    }
    else {
        signal(SIGUSR1, funkcija);
        while(1)
            if ( gautas_signalas == 1 ) {
                char pavarde[BUFLEN];
                printf( "VAIKAS: signala gavau!\n" );
                read ( fd[0], &pavarde, sizeof(pavarde));
                printf ("%s\n", pavarde);
                printf( "VAIKAS: baigiu darba.\n" );
                return 0;
            }
    }
}
