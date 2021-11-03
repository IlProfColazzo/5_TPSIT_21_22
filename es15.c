#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
 Scrivere un programma che generi N processi figli (N>0 dato in input). 
 Ogni figlio dovrà porsi in sleep per un numero casuale di secondi (tra 0 e 20) 
 e poi terminare con uno stato random (compreso tra 0 e 255). 
 Il processo padre dovrà stampare l’ordine di creazione, 
 l’ordine di terminazione dei figli (PID) e il relativo stato; 
 poi terminerà la sua esecuzione, ma solamente quando tutti i suoi figli 
 terminato.
*/

int main()
{	
	pid_t f, figlioTerminato;
	int N, wstatus;
	
	printf("Dammi il valore di N: ");
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		f = fork();
		if(f == 0){
			//processo figlio
			srand(getpid());
			int r = rand()%21;
			int exitStatus = rand()%256;
			sleep(r);
			exit(exitStatus);
		}
		else if(f > 0){
			printf("Creato figlio con PID = %d\n",f);
		}
		else{
			printf("ERRORE\n");
		}
	}
	for(int i=0; i<N; i++){
		figlioTerminato=wait(&wstatus);
		if(WIFEXITED(wstatus))
			printf("E' appena terminato il figlio con PID = %d con stato di uscita = %d\n",figlioTerminato,WEXITSTATUS(wstatus));
	}
	
    return 0;
}
