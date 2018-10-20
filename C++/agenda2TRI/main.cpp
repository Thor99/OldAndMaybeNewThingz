#include "agenda.h"
#include <iostream>
#include <string>
#include <utility>
#include <regex>

using namespace std;

int main()
{

    cout << "Bem vindo a agenda de contatos! (USE MAIUSCULO)\n";
    cout << "Para sair, digite BOTELHO\n";
    cout << "Para adicionar um contato: ADD [primeiro nome] [email] [telefone]\n";
    cout << "Para remover um contato: REMOVE [primeiro nome]\n";
    cout << "Para buscar as informações sobre um contato: GET [primeiro nome]\n";
    cout << "Para listar todos os contatos: LIST\n\n";

    string option;
    Agenda agenda;
    while(cin >> option)
    {
        if(option == "BOTELHO")
        {
        	return 0;
        }

        if(option == "ADD")
        {
            string nome, email, telefone;
            cin >> nome >> email >> telefone;

        	if(agenda.GetContact(nome).second != "ERR-NOT-FOUND")
        	{
        	   cout << "Contato já existe!\n";
        	}

        	else
        	{
    	   agenda.AddContact(nome, email, telefone);
        	}
        }

        else if(option == "REMOVE")
        {
            string nome;
            cin >> nome;

        	if(agenda.GetContact(nome).second == "ERR-NOT-FOUND")
        	{
                cout << "Contato não existe!\n";
        	}

        	else
        	{
        	   agenda.RemoveContact(nome);
        	}
        }

        else if(option == "GET")
        {
        	string nome;
        	cin >> nome;

        	if(agenda.GetContact(nome).first == "ERR-NOT-FOUND")
        	{
        	   cout << "Contato não existe!\n";
        	}

        	else
        	{
        	   cout << "Nome: " << nome << "; Email: " << agenda.GetContact(nome).first << "; Telefone: " << agenda.GetContact(nome).second << "\n";
        	}
        }

        else if(option == "LIST")
        {
        	agenda.PrintContacts();
        }

        else
        {
        	cout << "Opção incorreta!\n\n";
        }
    }
}
