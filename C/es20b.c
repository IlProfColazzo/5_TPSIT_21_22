#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere i programmi che permettano di eseguire le seguenti operazioni 
con il massimo grado di parallelismo:
> ( 3 + 2 ) * ( 5 + 7 ) + ( 8 – 3 )
*/

int main()
{	
	int ris, a, b, c;
    pid_t pid1, pid2;
    
    pid1 = fork();
    if(pid1 == 0) {
        b = 5 + 7;
        exit(b);
    }
    else if(pid1 > 0){
        pid2 = fork();
        if(pid2 == 0) {
            c = 8 - 3;
            exit(c);
        }
        else if(pid2 > 0){
            a = 3 + 2;
        }
		else
			printf("ERRORE\n");
    }
	else
		printf("ERRORE\n");
    
    waitpid(pid1, &b, 0);
	if(WIFEXITED(b))
		b = WEXITSTATUS(b);
    
    waitpid(pid2, &c, 0);
    if(WIFEXITED(c))
		c = WEXITSTATUS(c);
    
    ris = a * b + c;
    printf("Il risultato finale e': %d\n", ris);
    return 0;
}
