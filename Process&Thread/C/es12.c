#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
Scrivere un programma che generi un processo figlio, 
il quale dovrà stampare il proprio PID e poi terminare. 
Il processo padre, invece, dovrà porsi in sleep per un numero casuale 
di secondi (tra 0 e 20) e successivamente attendere la terminazione 
del figlio, prima di concludere.
*/

int main()
{	
	pid_t f;
	f = fork();
	if(f == 0){
		//processo figlio
		//in questo caso il figlio rimane zombie perchè termina prima che 
		//il padre esegua la wait.
		printf("Sono il figlio con PID = %d\n",getpid());
	}
	else if(f > 0){
		//processo padre
		srand(time(NULL));
		int r = rand()%21; 
		sleep(r);
		printf("E' appena terminato il figlio con PID = %d\n",wait(NULL));
	}
	else{
		printf("ERRORE\n");
	}

	
    return 0;
}
