#ifdef _MSC_VER
#pragma once
#endif
#ifdef ASYN_ACCEPT_RESULT_H_
#define ASYN_ACCEPT_RESULT_H_
#include "Asyn_Result.h"

class Asyn_Accept_Result:public Asyn_Result
{
public:
	Asyn_Accept_Result(void);
	~Asyn_Accept_Result(void);
	virtual int complete(int byte_transfeered,
		int success,
		const void* complet_key);
	virtual int success();
	virtual int byte_transferred();
};
#endif
