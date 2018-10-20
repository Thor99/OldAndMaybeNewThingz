#ifndef _SEM_H_
#define _SEM_H_

#include <windows.h>
typedef HANDLE Sem;

Sem sem_create(char const* name, int initial, int max)
{
	return CreateSemaphore(NULL, initial, max, name);
}

void sem_down(Sem s)
{
	WaitForSingleObject(s, INFINITE);
}

void sem_up(Sem s)
{
	ReleaseSemaphore(s, 1, NULL);
}

#endif
