#ifndef SOCK_STREAM_H_
#define SOCK_STREAM_H_
#include <string>
#include <WinSock2.h>
#define SOCK_STREM_EXPORT_ __declspec(dllexport)
using namespace std;
class SOCK_STREM_EXPORT_ sock_stream
{
public:
	sock_stream(void);
	~sock_stream(void);
	int sends(std::string buf, int size);
	int recvs(std::string buf, int size);
	void setHandle(SOCKET hanle_);
private:
	SOCKET sck_handle_;
};
#endif /*SOCK_STREAM_H_*/

