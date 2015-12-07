#include "StdAfx.h"
#include "simplelog.h"

simplelog::simplelog(void)
{
}


simplelog::~simplelog(void)
{
}

void simplelog::Log(const char* srcName, int lineNo, int level, const char* fmt...)
{
	va_list ap;
	char msg[2000];
	va_start(ap, fmt);
	vsprintf(msg, fmt, ap);
	va_end(ap);
	log(msg, srcName, lineNo, level);
}

void simplelog::log(char* msg, const char* sourcename, int lineno, int level)
{
	char  strPath[260]={0};

	HANDLE  hFile=::CreateFile(TEXT("log.log"), GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_READ|FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile==INVALID_HANDLE_VALUE)return ;
	SetFilePointer(hFile,0,0,FILE_END);
	std::string logstr;
	logstr.append(sourcename);
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	char stime[36];
	char buf[2048];
	time_t logtime;
	time(&logtime);
	strftime(stime, 36, "%Y-%m-%d %H:%M:%S", localtime(&logtime));
	sprintf(buf, "%s [%s#%d] %s -- %s\r\n", stime, sourcename, lineno, LogLevelName[level], msg);
	DWORD dwLen=0;
#ifdef DEBUG_
	printf("%s", buf);
#endif
	::WriteFile(hFile,buf,strlen(buf),&dwLen,NULL);
	CloseHandle(hFile);
}