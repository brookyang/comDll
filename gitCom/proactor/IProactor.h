#ifndef _MSC_VER
#pragma once
#endif

#ifndef IPROACTOR_H_
#define IPROACTOR_H_
#include "../public/com_define.h"
#include "Asyn_Handle.h"

class ASYN_EXPORT IProactor
{
public:
	IProactor(void);
	~IProactor(void);
	virtual int register_handle(Asyn_Handle* handle, const void* complet_key) = 0;
	virtual int remove_handle(Asyn_Handle* handle, const void* complet_key) = 0;
	virtual void handle_events() = 0;
};
#endif

