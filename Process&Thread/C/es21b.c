#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>
#define N 1000

/*
Scrivere un programma in cui un processo padre P inizializza 
un vettore di interi di interi di dimensione N = 1000 con dei numeri
scelti in modo casuale (tra 0 e 52).
Successivamente crea tre processi figli F1, F2, F3. 
Il processo F1 si occupa di calcolare il valore minimo presente nel vettore,
il processo F2 calcola il valore massimo e il processo F3 calcola la media. 
Ogni processo figlio restituisce al padre il valore calcolato dopo aver dormito 
per un tempo casuale compreso tra 10 e 20 secondi.
Il processo padre si occuperà di stampare, 
con un opportuno messaggio esplicativo, i valori restituiti dai figli.
Il programma deve essere scritto in due versioni: 
una prima versione utilizzando solo la funzione wait() 
e una seconda versione utilizzando solo la funzione waitpid().
*/

int main(){
	srand(getpid());
	int status;
	int v[N];
	for(int i=0;i<N;i++){
		v[i]=rand()%53;	
	}
	pid_t f=fork();
	if(f==0){
		//figlio 1
		srand(getpid());
		int min = v[0];
		for(int i=0;i<N;i++){
			if(v[i]<min){
				min = v[i];
			}
		}
		sleep((rand()%10)+10);
		exit(min);
	}else if(f>0){
		//padre
		pid_t f1=fork();
		if(f1==0){
			//figlio 2
			srand(getpid());
			int max = v[0];
			for(int i=0;i<N;i++){
				if(v[i]>max){
					max = v[i];
				}
			}
			sleep((rand()%10)+10);
			exit(max);
		}else if(f1>0){
			//padre
			pid_t f2=fork();
			if(f2==0){
				//figlio 3
				srand(getpid());
				int somma=0;
				for(int i=0;i<N;i++){
					somma +=v[i];
				}
				int media = somma/N;
				sleep((rand()%10)+10);
				exit(media);
			}else if(f2>0){
				//padre
				for(int i=0;i<3;i++){
					pid_t morto = wait(&status);
					if(morto==f){
						// stampa min
						if (WIFEXITED(status)) {
					    int min = WEXITSTATUS(status);
					    printf("il valore minore all'interno del vettore :%d\n", min);
						}
					}else if(morto==f1){
						// stampa max
						if (WIFEXITED(status)) {
					    int max = WEXITSTATUS(status);
					    printf("il valore massimo all'interno del vettore :%d\n", max);
						}
					}else if(morto==f2){
						// stampa media
						if (WIFEXITED(status)) {
					    int media = WEXITSTATUS(status);
					    printf("la media dei valori all'interno del vettore :%d\n", media);
						}
					}
				}
			}else{
				printf("errore");
			}
	}else{
			printf("errore");
		}
	}else{
		printf("errore");
	}
	return 0;
}
