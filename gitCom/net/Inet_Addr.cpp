#include "StdAfx.h"
#include "Inet_Addr.h"

Inet_Addr::Inet_Addr(const char* ipc, int port)
{
	memset(&sckaddr, 0, sizeof(struct sockaddr_in));
	sckaddr.sin_family = AF_INET;
	sckaddr.sin_port = htons(port);
	if (ipc != NULL && strlen(ipc) > 0)
	{
		sckaddr.sin_addr.S_un.S_addr = inet_addr(ipc);
	}
	else
	{
		sckaddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	}
}


Inet_Addr::~Inet_Addr(void)
{
	memset(&sckaddr, 0, sizeof(struct sockaddr_in));
}

const char* Inet_Addr::ip()
{
	return ::inet_ntoa(sckaddr.sin_addr);
}

int Inet_Addr::port()
{
	return ntohs(sckaddr.sin_port);
}

int Inet_Addr::size()
{
	return sizeof(struct sockaddr_in);
}

sockaddr* Inet_Addr::saddr()
{
	return reinterpret_cast<sockaddr*>(&sckaddr);
}