#include "StdAfx.h"
#include "WIN32_Proactor.h"


WIN32_Proactor::WIN32_Proactor(void)
{
	this->numberOfThread = 1;
	this->comPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE,
										   0,
										   0,
										   this->numberOfThread);
	if(this->comPort == 0)
		INFO("create comport error, error code %s", this->comPort);

}


WIN32_Proactor::~WIN32_Proactor(void)
{
}


int WIN32_Proactor::register_handle(Asyn_Handle* handle, const void* complet_key)
{
	ULONG_PTR comple_key(reinterpret_cast<ULONG_PTR>(complet_key));
	PROACTOR_HANDLE ph = ::CreateIoCompletionPort(hanle, 
												  this->comPort,
												  comple_key,
												  this->numberOfThread);
	if (ph == 0)
	{
		return -1;
	}
	return 0;
}

int WIN32_Proactor::remove_handle(Asyn_Handle* handle, const void* complet_key)
{
	return 0;
}

void WIN32_Proactor::handle_events()
{
	COM_OVERLAPPED* overlapped = 0;
	u_long byte_transferred = 0;
	ULONG_PTR complet_key = 0;
	BOOL result = ::GetQueuedCompletionStatus(this->comPort,
											  &byte_transferred,
											  &complet_key,
											  &overlapped,
											  PROACTOR_INFINITE);
	if (result == false || overlapped == 0)
	{
		INFO("proactor handle_events error");
	}
	else
	{

	}
}
