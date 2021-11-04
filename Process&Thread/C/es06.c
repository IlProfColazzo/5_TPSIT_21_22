#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Scrivere un programma che riceva come input un numero intero e, 
successivamente, generi due processi figli: il primo processo figlio 
sommi 15 a tale numero, il secondo sommi 10 a tale numero, 
mentre il padre lo lasci immutato. Visualizzare, in ognuno dei processi, 
il valore della variabile modificata.
*/

int main()
{	
	int n;
	pid_t f1,f2;
	
	printf("Inserisci un numero intero: ");
	scanf("%d",&n);
	
	f1 = fork();
	if(f1==0){
		n+=15;
		printf("Sono f1 ed n=%d\n",n);
	}
	else if(f1>0){
		f2 = fork();
		if(f2==0){
			n+=10;
			printf("Sono f2 ed n=%d\n",n);
		}
		else if(f2>0){
			printf("Sono il padre ed n=%d\n",n);	
		}
		else{
			printf("Errore");
		}
	}
	else{
		printf("Errore");
	}
	
	
    return 0;
}
