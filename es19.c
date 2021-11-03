#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere un programma che, una volta avviato, generi un processo figlio
ed entrambi effettuino un calcolo parallelo. 
Il padre calcolerà x = 3 + 2 mentre il figlio y = 6 - 2, 
restituendo come stato di uscita il risultato dell’operazione. 
Il padre, dopo aver atteso la conclusione del figlio, calcolerà e 
visualizzerà il risultato finale z = x + y.
*/

int main()
{	
	pid_t f;
	int wstatus;

	f = fork();
	if(f == 0){
		//processo figlio
		int y = 6 - 2;
		exit(y);
	}
	else if(f < 0){
		printf("ERRORE\n");
	}
	else{
		//processo padre
		wait(&wstatus);
		if(WIFEXITED(wstatus)){
			int x = 3 + 2;
			int y = WEXITSTATUS(wstatus);
			int z = x + y;
			printf("%d + %d = %d\n",x,y,z);
		}
	}
	
    return 0;
}
