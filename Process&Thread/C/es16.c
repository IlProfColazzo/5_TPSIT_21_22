#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere un programma che generi un processo figlio, 
il quale dovrà chiedere in input la vostra età e restituirla 
al processo padre in modo tale che quest’ultimo possa visualizzarla.
*/

int main()
{	
	pid_t f;
	int wstatus;
	
	f = fork();
	if(f == 0){
		//processo figlio
		int eta;
		printf("Dammi la tua eta': ");
		scanf("%d",&eta);
		exit(eta);
	}
	else if(f > 0){
		wait(&wstatus);
		if(WIFEXITED(wstatus))
			printf("L'eta' e' uguale a %d anni\n",WEXITSTATUS(wstatus));
	}
	else{
		printf("ERRORE\n");
	}

    return 0;
}
