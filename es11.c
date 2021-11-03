#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
Scrivere un programma che generi un processo figlio, 
il quale dovrà porsi in sleep per un numero casuale di secondi (tra 0 e 20)
e poi terminare. Il processo padre dovrà attendere la terminazione 
del processo figlio, visualizzandone il PID una volta che avrà concluso.
*/

int main()
{	
	pid_t f;
	f = fork();
	if(f == 0){
		//processo figlio
		srand(time(NULL));
		int r = rand()%21; 
		sleep(r);
	}
	else if(f > 0){
		//processo padre
		printf("E' appena terminato il figlio con PID = %d\n",wait(NULL));
	}
	else{
		printf("ERRORE\n");
	}
	
    return 0;
}
