#include "sem.h"
 
int main ()
{
/*
Cria um semáforo de nome “Semaforo1” com valor inicial 0 e valor máximo 5.
Caso um semáforo com esse nome já tenha sido criado em outro processo, apenas o referencia, sem alterar seu valor.
Guarda o semáforo na variável s.
*/
            Sem s = sem_create("Semaforo1", 0, 5);  
 
            //sem_down(s);  // Efetua uma operação de DOWN em s.
 
            sem_up(s);  // Efetua uma operação de UP em s.
 
            return 0;
}
