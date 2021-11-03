#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Scrivere i programmi che permettano di eseguire le seguenti operazioni 
con il massimo grado di parallelismo:
> ( 3 + x ) – ( 5 + y ) * ( 7 * z + 3 )	
x, y e z sono letti in input dal padre
*/

int main()
{	
	int x, y, z, ris, a, b, c;
    pid_t pid1, pid2;
    
    printf("Inserisci valore per la variabile x: ");
    scanf("%d", &x);
    printf("Inserisci valore per la variabile y: ");
    scanf("%d", &y);
    printf("Inserisci valore per la variabile z: ");
    scanf("%d", &z);
    
    pid1 = fork();
    if(pid1 == 0) {
        b = 5 + y;
        exit(b);
    }
    else if(pid1 > 0){
        pid2 = fork();
        if(pid2 == 0) {
            c = 7 * z + 3;
            exit(c);
        }
        else if(pid2 > 0){
            a = 3 + x;
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
    
    ris = a - b * c;
    printf("Il risultato finale e': %d\n", ris);
	
    return 0;
}
