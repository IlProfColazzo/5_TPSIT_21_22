#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che generi un numero di processi figli definiti 
dall’utente, mediante la lettura in input di un valore intero. 
Visualizzare, per ciascuno di essi, il proprio PID e quello del padre.
*/

int main()
{	
	pid_t f;
	int nFigli;
	
	printf("Dammi il numero di figli che vuoi creare: ");
	scanf("%d",&nFigli);

	for(int i=0; i<nFigli; i++){
		f = fork();
		if(f==0){
			//figlio i-esimo
			printf("Sono il figlio %d con PID = %d e PPID = %d\n",i+1,getpid(),getppid());
			exit(1); //se non ci fosse la exit() il figlio continuerebbe
			//ad eseguire il codice e quindi a ciclare e a generare figli.
			//Al posto di creare nFigli processi si avrebbero 2^nFigli processi.
		}
		else if(f<0){
			printf("ERRORE\n");
		}
	}
	sleep(3);
    return 0;
}
