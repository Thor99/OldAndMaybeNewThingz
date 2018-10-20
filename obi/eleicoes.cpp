#include <stdio.h>
#include <string.h>
#include <map>
#define MAXC 100000

int main(){
  int prefs[MAXC];
  int n, vencedor;
  int nVotes = 0;

  std::map<int, int>::iterator it;

  std::map<int, int> votes;

  memset(prefs, 1, sizeof(prefs));

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &prefs[i]);

    if(votes.count(prefs[i])){ // Se esse prefeito já tiver sido votado, incrementa o voto
      votes[prefs[i]]++;
    } else { // Se é a primeira vez que o prefeito foi votado, seta o voto numero de votos como 1
      votes[prefs[i]] = 1;
    }
  }

  for(it = votes.begin(); it != votes.end(); it++) { // Pegara o prefeito com maior numero de votos
    if(it->second > nVotes){
      nVotes = it->second;
      vencedor = it->first;
    }
  }

  printf("%d\n", vencedor);

  return 0;
}
