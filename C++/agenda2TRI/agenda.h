#ifndef AGENDA_H
#define AGENDA_H
#include <map>
#include <string>
#include <utility>

using namespace std;

class Agenda
{
public:
	Agenda() = default;
	void AddContact(string nome, string email, string telefone);
	void RemoveContact(string nome);
	pair<string, string> GetContact(string nome) const;
	void PrintContacts() const;

private:
	map<string, pair<string, string> > m_agenda; // (nome, (email, telefone))
};
#endif
