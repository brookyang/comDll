#ifdef _MSC_VER
	#pragma once
#endif
#ifndef INET_ADDR_H_
#define INET_ADDR_H_
#include <string>
#include <WinSock.h>
using namespace std;

#define INET_EXPORT_ __declspec(dllexport)

class INET_EXPORT_ Inet_Addr
{
public:
	Inet_Addr(const char* ipc, int port);
	~Inet_Addr(void);
	const char* ip();
	int port();
	int size();
	sockaddr* saddr();
private:
	sockaddr_in sckaddr;
};

#endif /*INET_ADDR_H_*/
