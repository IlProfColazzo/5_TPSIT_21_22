#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che, una volta avviato, crei un processo figlio: 
il processo padre visualizzi l’alfabeto maiuscolo intervallando le lettere 
con un ritardo di 3 secondi, mentre il processo figlio visualizzi 
quello minuscolo (senza alcun ritardo). Utilizzare la tabella ASCII e il cast in int a char.
*/

int main()
{	
	
	pid_t pidFork;
	
	pidFork = fork();
	
	if(pidFork==0){
		//figlio
		for(int i=97; i<=122;i++){
			printf("%c\n",i);
		}
	}
	else if (pidFork>0){
		//padre
		for(char i='A'; i<='Z';i++){
			printf("%c\n",i);
			sleep(3);
		}
	}
	else{
		printf("ERRORE\n");
	}
	
    return 0;
}
