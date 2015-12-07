#ifdef _MSC_VER
#pragma once
#endif
#ifdef WIN32_PROACTOR_H_
#define WIN32_PROACTOR_H_
#include "IProactor.h"

class WIN32_Proactor:public IProactor
{
public:
	WIN32_Proactor(void);
	~WIN32_Proactor(void);
	virtual int register_handle(Asyn_Handle* handle, const void* complet_key);
	virtual int remove_handle(Asyn_Handle* handle, const void* complet_key);
	virtual void handle_events();
private:
	int comPort;
	DWORD numberOfThread;
};
#endif
