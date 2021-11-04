#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che chieda in input due valori interi e, successivamente,
generi un processo figlio: il padre si occuperà di calcolare e visualizzare 
il prodotto dei due valori, il figlio la somma.
*/


int main()
{	
	pid_t f;
	int a,b;
	
	printf("Inserisci due valori interi: ");
	scanf("%d%d",&a,&b);
	
	f = fork();
	if(f==0){
		//figlio
		printf("Sono il figlio, la somma tra %d e %d vale %d\n",a,b,a+b);
	}
	else if(f>0){
		printf("Sono il padre, il prodotto tra %d e %d vale %d\n",a,b,a*b);
		sleep(1);
	}
	else{
		printf("ERRORE\n");
	}
    return 0;
}
