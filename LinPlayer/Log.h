#ifndef _LOG_H
#define _LOG_H

#include <concrt.h>
#include <stdio.h>
#include <stdint.h>
#include <mutex>

class CSingletonLog  
{  
public:
	const static uint8_t FileNameLen = 100;

private:  
	CSingletonLog()   //���캯����˽�е�  
	{  
	}  
	CSingletonLog(const CSingletonLog &);  
	CSingletonLog & operator = (const CSingletonLog &);  

	FILE *fp;
	char logName[FileNameLen];
	std::mutex _mutex;
public:  
	static CSingletonLog & GetInstance()  
	{  
		static CSingletonLog instance;   //�ֲ���̬����  
		return instance;  
	}  

	void Init(const char *path = NULL);
	void FlashLog(const char *msg, ...);
};  

#define LogIns CSingletonLog::GetInstance()


#endif //#define _LOG_H