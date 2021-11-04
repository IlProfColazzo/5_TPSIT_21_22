#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere un programma in cui un processo padre P crea due processi figli 
(prima F1 e poi F2) e ne attende la terminazione in ordine inverso. 
Ciascuno dei due figli, a sua volta, crea due processi figli 
(F1 crea prima G1 e poi H1; F2 crea prima G2 e poi H2) 
e ne attende la terminazione nell’ordine in cui li ha creati.
*/

int main()
{	
	pid_t f1, f2;
	
	f1 = fork();
	if(f1 == 0){
		pid_t g1, h1;
	
		g1 = fork();
		if(g1 == 0){
			exit(0);
		}
		else if(g1 > 0){
			h1 = fork();
			if(h1 == 0){
				exit(0);
			}
			else if(h1 > 0){
				waitpid(g1,NULL,0);
				waitpid(h1,NULL,0);
			}
			else{
				printf("ERRORE\n");
			}
		}
		else{
			printf("ERRORE\n");
		}
	}
	else if(f1 > 0){
		f2 = fork();
		if(f2 == 0){
			pid_t g2, h2;
	
			g2 = fork();
			if(g2 == 0){
				exit(0);
			}
			else if(g2 > 0){
				h2 = fork();
				if(h2 == 0){
					exit(0);
				}
				else if(h2 > 0){
					waitpid(g2,NULL,0);
					waitpid(h2,NULL,0);
				}
				else{
					printf("ERRORE\n");
				}
			}
			else{
				printf("ERRORE\n");
			}
		}
		else if(f2 > 0){
			waitpid(f2,NULL,0);
			waitpid(f1,NULL,0);
		}
		else{
			printf("ERRORE\n");
		}
	}
	else{
		printf("ERRORE\n");
	}
    return 0;
}
