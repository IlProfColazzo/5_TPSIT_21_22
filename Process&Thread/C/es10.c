#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che generi un processo figlio: 
il padre dovrà porsi in sleep per 3 secondi e poi terminare; 
il figlio, invece, continuerà a visualizzare il PID del processo 
padre fino a quando verrà adottato dal processo init a causa della
 terminazione del padre.
*/

int main()
{	
	pid_t pid = fork();
	
	if(pid==0){
		//figlio
		//il figlio capisce che è stato adottato dal processo init
		//quando il PID del padre (ottenuto tramite getppid()) diventa 1.
		int padre = getppid();
		while(padre!=1){
			printf("PPID = %d\n",padre);
			padre = getppid();
		}
	}
	else if(pid>0){
		//padre
		sleep(3);
	}
	else{
		printf("ERRORE\n");
	}
	
    return 0;
}
