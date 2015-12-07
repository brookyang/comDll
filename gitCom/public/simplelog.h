#ifndef _MSC_VER
#pragma once
#endif
#ifndef SIMLE_LOG_H_
#define SIMLE_LOG_H_

#include <string>
#include <time.h>
using namespace std;

#define LOG_EXPORT_ __declspec(dllexport)

static const char* LogLevelName[]={"Debug","Info","Warn","Error"};

#define    INFO(...)    simplelog::Log(__FILE__, __LINE__, simplelog::Log_Info, __VA_ARGS__)
#define	   ERROR(...)   simplelog::Log(__FILE__, __LINE__, simplelog::Log_Error,__VA_ARGS__)
#define	   WARN(...)	simplelog::Log(__FILE__, __LINE__, simplelog::Log_Warn, __VA_ARGS__)
#define    DEBUG(...)   simplelog::Log(__FILE__, __LINE__, simplelog::Log_Debug, __VA_ARGS__)

class LOG_EXPORT_ simplelog
{
public:
	static void Log(const char* srcName, int lineNo, int level, const char* fmt...);
public:
	static const int Log_Debug=0;
	static const int Log_Info=1;
	static const int Log_Warn=2;
	static const int Log_Error=3;
private:
	static char fileName[256];
	//static int  level;
	static void log(char* msg, const char* sourcename, int lineno, int level);
	//static int  getLevel()
	//{
	//	return level;
	//}
private:
	simplelog();
	~simplelog(void);
};
#endif