#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Scrivere un programma che generi tre processi figli, 
ognuno dei quali scriverà una delle seguenti frasi: 
"Ciao, io sono Qui", "Ciao, io sono Quo" e "Ciao, io sono Qua". 
Visualizzare, per ogni processo, il proprio PID e quello del padre.*/

int main()
{

	pid_t pidFork;
	char l[3] = {'i','o','a'};
	
	
	for(int i=0;i<3;i++){
		pidFork = fork();
		if(pidFork==0){
			printf("Ciao io sono Qu%c, PID = %d e PPID =%d\n",l[i],getpid(),getppid());
			exit(0);
		}
		else if(pidFork<0){
			printf("ERRORE\n");
		}
	}
	sleep(2);
	
    return 0;
}
