#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
Scrivere un programma che generi N processi figli (N>0 dato in input). 
Ogni figlio dovrà porsi in sleep per un numero casuale di secondi 
(tra 0 e 20) e poi terminare. Il processo padre dovrà stampare 
l’ordine di creazione e l’ordine di terminazione dei figli (PID); 
poi terminerà la sua esecuzione, ma solamente quando tutti i suoi 
figli avranno terminato.
*/

int main()
{	
	pid_t f;
	int N;
	
	printf("Dammi il valore di N: ");
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		f = fork();
		if(f == 0){
			srand(getpid());
			int r = rand()%21;
			//processo figlio
			sleep(r);
			exit(0);
		}
		else if(f > 0){
			printf("Creato figlio con PID = %d\n",f);
		}
		else{
			printf("ERRORE\n");
		}
	}
	for(int i=0; i<N; i++){
		printf("Terminato figlio con PID = %d\n",wait(NULL));
	}
    return 0;
}
