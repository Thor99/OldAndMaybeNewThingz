#include "agenda.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

void Agenda::AddContact(string nome, string email, string telefone)
{
	m_agenda[nome] = make_pair(email, telefone);
}

void Agenda::RemoveContact(string nome)
{
	m_agenda.erase(m_agenda.find(nome));
}

pair<string, string> Agenda::GetContact(string nome) const
{
	map<string, pair<string, string> >::const_iterator it =  m_agenda.find(nome);

	if(it == m_agenda.end())
	{
		return make_pair("ERR-NOT-FOUND", "ERR-NOT-FOUND");
	}

	else
	{
		return make_pair((*it).second.first, (*it).second.second);
	}
}

void Agenda::PrintContacts() const
{
	map<string, pair<string, string> >::const_iterator it;

	for(it = m_agenda.begin(); it != m_agenda.end(); ++it)
	{
		cout << "Nome: " << (*it).first << "; Email: " << (*it).second.first << "; Telefone: " << (*it).second.second << "\n";
	}

	cout << "\n";
}


