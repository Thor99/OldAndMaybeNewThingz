#include <stdio.h>
#include <string.h>


struct Aluno{
	char nome[100];
	float nota1;
	float nota2;
	float nota3;
};


int main(){
	struct Aluno alunos[100];
	int i;
	int numero_alunos;
	FILE* f = fopen("exercicio_structs_2.txt", "wt");
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	printf("Quantos alunos tem na classe: ");
	scanf("%d", &numero_alunos);
	
	for(i = 0; i < numero_alunos; i++){
		printf("Diga o nome do aluno: ");
		scanf("%s", alunos[i].nome);
		printf("Diga sua primeira nota: ");
		scanf("%f", &alunos[i].nota1);
		printf("Diga sua segunda nota: ");
		scanf("%f", &alunos[i].nota2);
		printf("Diga sua terceira nota: ");
		scanf("%f", &alunos[i].nota3);
	}
	
	for(i = 0; i < numero_alunos; i++){
		if((alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3 >= 7.0){
			fprintf(f, "%s APROVADO\n", alunos[i].nome);
		}
		else{
			fprintf(f, "%s REPROVADO\n", alunos[i].nome);
		}
	}
	
	
	fclose(f);
	
	return 666;
}