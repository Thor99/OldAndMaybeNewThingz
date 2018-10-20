#include <stdio.h>
#include <windows.h> // biblioteca do sistema operacional. Usaremos para poder botar dois processos querendo o mesmo recurso com o Sleep

int main(void){
	
	char s[100];
	int i;
	FILE* f = fopen("famb_write.txt", "at"); // se fosse wt, toda vez que o programa fosse rodado ele apagaria o que tinha antes para escrever de novo.
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	for(i = 0; i < 100; i++){
		fprintf(f, "henry lixo demais\n");
		fflush(f); // Salva no mesmo instante em que escreve
		Sleep(100);
	}
	
	fclose(f);
	
	return 666;
}