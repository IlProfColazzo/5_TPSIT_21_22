#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere un programma che generi due processi figli, 
i quali dovranno porsi in sleep per un numero casuale di secondi 
(tra 0 e 255) e poi terminare la loro esecuzione. 
Il processo padre dovrà rimanere in attesa solo del primo tra i figli 
che avrà terminato, visualizzandone il PID e il numero di 
secondi in cui ha dormito.
*/

int main()
{	
	pid_t f, figlioTerminato;
	int wstatus;
	
	for(int i=0; i<2; i++){
		f = fork();
		if(f == 0){
			//processo figlio
			srand(getpid());
			int r = rand()%256;
			sleep(r);
			exit(r);
		}
		else if(f < 0){
			printf("ERRORE\n");
		}
	}
	figlioTerminato=wait(&wstatus);
	if(WIFEXITED(wstatus))
		printf("E' appena terminato il figlio con PID = %d e ha dormito %d secondi.\n",figlioTerminato,WEXITSTATUS(wstatus));
	
    return 0;
}
