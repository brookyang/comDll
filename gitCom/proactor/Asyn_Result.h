#ifdef _MSC_VER
	#pragma once
#endif
#ifdef ASYN_RESULT_
#define ASYN_RESULT_

class Asyn_Result
{
public:
	Asyn_Result(void);
	~Asyn_Result(void);
	virtual int complete(int byte_transfeered,
						 int success,
						 const void* complet_key) = 0;
	virtual int success() const = 0;
	virtual int byte_transferred() const = 0;
};
#endif