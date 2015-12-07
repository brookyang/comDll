#include "StdAfx.h"
#include "sock_stream.h"


sock_stream::sock_stream(void)
{
}


sock_stream::~sock_stream(void)
{
	if (this->sck_handle_ > 0)
	{
		closesocket(this->sck_handle_);
	}
}

void sock_stream::setHandle(SOCKET hanle_)
{
	this->sck_handle_ = hanle_;
}

int sock_stream::sends(std::string buf, int size)
{
	return ::send(sck_handle_, (char*)buf.c_str(), size, 0);
}

int sock_stream::recvs(std::string buf, int size)
{
	return ::recv(sck_handle_, (char*)buf.c_str(), size, 0);
}
