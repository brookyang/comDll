#ifdef _MSC_VER
#pragma once
#endif
#ifndef WIN32_ASYN_RESULT_
#define WIN32_ASYN_RESULT_
#include "../public/com_define.h"
#include "Asyn_Result.h"

class WIN32_Asyn_Result:public Asyn_Result, public OVERLAPPED
{
public:
	WIN32_Asyn_Result(void);
	~WIN32_Asyn_Result(void);
	virtual int complete(int byte_transfeered,
						 int success,
						 const void* complet_key) = 0;
	virtual int success() const = 0;
	virtual int byte_transferred() const = 0;
	size_t  byte_tranfered;
	int		success;
	const void* complete_key;
};
#endif

