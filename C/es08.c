#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che generi due processi figli, 
i quali a loro volta generino un proprio processo figlio. 
Impostare opportunamente l’output in modo da rendere comprensibile 
quali siano le relazioni di «parentela» (pid e ppid).
*/

#define NFIGLI 2
int main()
{	
	pid_t f;

	for(int i=0; i<NFIGLI; i++){
		f = fork();
		if(f==0){
			//figlio i-esimo
			printf("Sono il figlio %d con PID = %d e PPID = %d\n",i+1,getpid(),getppid());
			pid_t figlioDiI = fork();
			if(figlioDiI==0){
				//figlio di i
				printf("Sono il figlio di %d e ho PID = %d\n",getppid(),getpid());
				exit(1);
			}
			else if(figlioDiI<0){
				printf("ERRORE\n");
			}
			sleep(1);
			exit(1);
		}
		else if(f<0){
			printf("ERRORE\n");
		}
	}
	sleep(3);
    return 0;
}
