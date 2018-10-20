#include "sem.h"
 
int main ()
{
/*
Cria um sem�foro de nome �Semaforo1� com valor inicial 0 e valor m�ximo 5.
Caso um sem�foro com esse nome j� tenha sido criado em outro processo, apenas o referencia, sem alterar seu valor.
Guarda o sem�foro na vari�vel s.
*/
            Sem s = sem_create("Semaforo1", 0, 5);  
 
            //sem_down(s);  // Efetua uma opera��o de DOWN em s.
 
            sem_up(s);  // Efetua uma opera��o de UP em s.
 
            return 0;
}
