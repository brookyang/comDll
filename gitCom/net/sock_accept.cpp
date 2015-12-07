#include "StdAfx.h"
#include "sock_accept.h"

sock_accept::sock_accept(Inet_Addr saddr)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1,1);
	err = WSAStartup(wVersionRequested,&wsaData);
	if (err != 0)
	{
		return;
	}
	if(LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}
	handle_ = socket(AF_INET, SOCK_STREAM, 0);
	::bind(handle_, saddr.saddr(), saddr.size());
	::listen(handle_, MAX_LISTEN);
}


sock_accept::~sock_accept(void)
{
	if (handle_ != -1)
	{
		closesocket(handle_);
	}
	if (stream != NULL)
	{
		delete stream;
	}
}

void sock_accept::setSockStream(sock_stream* sstream)
{
	this->stream = sstream;
}

void sock_accept::accept()
{
	stream->setHandle(::accept(handle_, NULL, NULL));
}