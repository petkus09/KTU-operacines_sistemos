#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MKrIlg 50

int main ( void )

{
   typedef struct
                   { int m, n;    /* matricos ismatavimai */
                     int Sk[ MKrIlg ][ MKrIlg ];
                   } MATRICA;

   int      x;                    /* isejimo variantas */
   int      fd[2];                /* deskriptoriu masyvas ( kanalui ) */
   FILE     *F;                   /* rodykle skaitymui/rasymui */
   pid_t    pid;                  /* Proceso identifikatorius */
   pid_t    tevopid;
   int      status;
   int      i, j;                 /* ciklu kintamieji */
   MATRICA  M;                    /* Duomenu matrica ( irasas ) */
   char     eil[1024];            /* Eilute duomenu spausdinimui */

   if ( pipe ( fd ) == -1 )
      { fprintf ( stderr, "Nepavyko sukurti programinio kanalo !\n" );
        exit    ( 1 );
      }
  /* ------------------- Dalijames ------------------ */

   pid = fork ();
   if ( pid == 0 )
  /* -------------------- Vaikas -------------------- */
      {
         read ( fd[0], &tevopid, sizeof (tevopid) );
         printf (" PID: %d\n", tevopid);
         printf ( "Vaikas baige darba ...\n" );
      }
   else if ( pid == -1 )
           {
             fprintf ( stderr, "Nepavyko sukurti vaiko !\n" );
             exit    ( 4 );
           }
        else
           {
 /* ------------ Tevo procesas---------- */
             tevopid = getpid();
             write ( fd[1], &tevopid, sizeof (tevopid) );
           }
   return 0;
}
