#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere i programmi che permettano di eseguire le seguenti operazioni 
con il massimo grado di parallelismo:
> 5 * [ ( 2 + 4 ) * ( 7 + 3 ) ] – 10
*/

int main()
{	
	int ris, a, b;
    pid_t pid;
    
    pid = fork();
    if(pid == 0) {
        b = 7 + 3;
        exit(b);
    }
    else if (pid > 0){
        a = 2 + 4;
    }
	else{
		printf("ERRORE\n");
	}
    
    waitpid(pid, &b, 0);
	if(WIFEXITED(b)){
		b = WEXITSTATUS(b);
		ris = 5 * (a * b) - 10;
		printf("Il risultato finale e': %d\n", ris);
	}
    return 0;
}
