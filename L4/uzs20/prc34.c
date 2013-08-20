#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[]) {
    const char Kl_pran[] = "fork() klaida, nepavyko sukurti naujo proceso!";
    pid_t pid;

    printf("Paleidziame pirmaji procesa ...\n");
    pid = fork();
    if ( pid < 0 ) {
        perror( Kl_pran );
        exit( 1 );
    }
    if ( pid == 0 ) {
        execl("../lab2/proc61b", "Pirmas procesas", argv[1], (const char *)0  );
        perror("pirmo execl() klaida");
        exit( 3 );
    }
    else {
        wait(NULL);
        printf("Pirmasis procesas baige darba.\n");
        printf("Paleidziame tevo procesa ...\n");
        printf("Tevas baigesi.\n");
        return 0;
    }
}

