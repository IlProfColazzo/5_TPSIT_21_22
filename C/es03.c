#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che, una volta avviato, generi un processo figlio. 
Entrambi i processi, padre e figlio, devono visualizzare: 
il proprio PID; il PID del padre; il valore restituito dalla funzione fork(). 
Impostare l’output in modo che sia chiaro quale fra i due processi, 
padre e figlio, stia fornendo le informazioni.

*/

int main()
{	
	pid_t f = fork();
	if(f==0){
		//figlio
		printf("Sono il figlio con PID = %d e PPID = %d, la fork mi ha restituito %d\n",getpid(),getppid(),f);
	}
	else if(f>0){
		printf("Sono il padre con PID = %d e PPID = %d, la fork mi ha restituito %d\n",getpid(),getppid(),f);
		sleep(1);
	}
	else{
		printf("ERRORE\n");
	}
    return 0;
}
