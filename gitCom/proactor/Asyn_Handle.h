#ifdef _MSC_VER
#pragma once
#endif

#ifndef ASYN_HANDLE_H_
#define ASYN_HANDLE_H_

class Asyn_Handle
{
public:
	Asyn_Handle(void);
	~Asyn_Handle(void);
	virtual handle_events();
};
#endif
