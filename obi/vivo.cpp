#include <stdio.h>

int main(){
	int quantParticipantesInicio, quantRodadas;
	int quantParticipantesRodada;
	int ordem;
	int acao;
	int teste = 1;
	int pos; // Posição de quem executa ação

	while(scanf("%d %d", &quantParticipantesInicio, &quantRodadas) == 2 && quantRodadas != 0){
		int participantes[101];

		for (int i = 0; i < quantParticipantesInicio; ++i){
			scanf("%d", &participantes[i]);
		}

		for (int i = 0; i < quantRodadas; ++i){
			pos = 0; // Sempre começa com o primeiro da fila

			scanf("%d %d", &quantParticipantesRodada, &ordem);

			for(int j = 0; j < quantParticipantesRodada; ++j){
				scanf("%d", &acao);

				if(acao != ordem){ // Se a ordem executada pelo participante na posição j for diferente da ordenada, o participante na posição j morre
					for(int k = pos; k < quantParticipantesRodada; k++){
						participantes[k] = participantes[k + 1]; // Tira o participante atual (que errou) da fila
					}
				} else {
					pos++; // Acertou, pula pro próximo participante
				}
			}
		}

		printf("Teste %d\n%d\n\n", teste, participantes[0]);

		teste++;
	}

	return 0;
}