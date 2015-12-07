#pragma once

#include <WinSock2.h>

#define PROACTOR_INFINITE 10000000

typedef int Event_Type;
typedef OVERLAPPED COM_OVERLAPPED;

typedef int PROACTOR_HANDLE;

enum
{
	ACCEPT_EVENT = 0,
	READ_EVENT = 1,
	WRITE_EVENT = 2,
	ERROR_EVENT = 3,
	TIMEOUT_EVENT
};



#define ASYN_EXPORT __declspec(dllexport)

