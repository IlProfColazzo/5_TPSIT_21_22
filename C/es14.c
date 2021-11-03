#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere un programma che generi un processo figlio, 
il quale dovrà porsi in sleep per 4 secondi e poi terminare. 
Il processo padre dovrà attendere la terminazione del processo figlio, 
visualizzandone il PID e il relativo stato di uscita una volta 
che avrà concluso.
*/

int main()
{	
	pid_t f;
	f = fork();
	int wstatus;
	if(f == 0){
		sleep(4);
		exit(4);
	}
	else if(f > 0){
		//processo padre
		wait(&wstatus);
		if(WIFEXITED(wstatus))
			printf("E' appena terminato il figlio con PID = %d con stato di uscita = %d\n",f,WEXITSTATUS(wstatus));
	}
	else{
		printf("ERRORE\n");
	}
	
    return 0;
}
