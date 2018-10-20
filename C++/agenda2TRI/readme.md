# Documentação do projeto "agenda", para a disciplina de C++, turma de 2016.

## Objetivo:

* Usar as estruturas de dados aprendida para criar uma agenda baseada no terminal.

* Treinar mais a divisão de um projeto (.cpp, .h)

## Código:

O projeto foi desenvolvido utilizando uma classe Agenda e um arquivo main, para rodar o projeto em sí.

As estruturas de dados utilizadas foram:

* pair

* map

Map foi utilizado para termos uma estrutura de chave valor, sendo a chave o nome do contato, e o valor um pair de strings (email, telefone).

## Como utilizar:

O projeto possui quatro comandos:

* **ADD**: Usado para adicionar um novo contato, precisando receber três parâmetros: primeiro nome, email e telefone (nesta ordem). Exemplo de uso: ```ADD thor thor@thor.com 1234-5678```.

* **REMOVE**: Usado para remover um contato, precisando receber um parâmetro: nome do contato. Exemplo de uso: ```REMOVE thor```.

* **GET**: Usado para printar informações sobre um contato específico, precisando receber um parâmetro: nome do contato. Exemplo de uso: ```GET thor```.

* **LIST**: Usado para printar as informações de todos os contatos da agenda, em ordem lexicográfica crescente, baseado no nome do contato. Não necessita de parâmetros. Exemplo de uso: ```LIST```.

* **BOTELHO**: Usado para sair do programa. Não necessita de parâmetros. Exemplo de uso: ```BOTELHO```.
