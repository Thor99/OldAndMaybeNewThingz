#include <stdio.h>
#include <vector>

using namespace std;

struct Aluno{
	int identificador;
	int media;
};

int main(){
	int N, turma=1;
	vector<Aluno> alunos;

	while(scanf("%d", &N) == 1 && N != 0){
		int maiorMedia=0;

		printf("Turma %d\n", turma++);

		for (int i = 0; i < N; ++i){
			alunos.push_back(Aluno());
			scanf("%d %d", &alunos[i].identificador, &alunos[i].media);
		}

		for (int i = 0; i < N; ++i){
			if(alunos[i].media > maiorMedia){
				maiorMedia = alunos[i].media;
			}
		}

		for (int i = 0; i < N; ++i){
			if(alunos[i].media == maiorMedia){
				printf("%d ", alunos[i].identificador);
			}	
		}

		printf("\n\n");
	}
	return 0;
}