#ifndef PARENTPROCESS_H_
#define PARENTPROCESS_H_

#include <windows.h>
#include <string>

class ParentProcess
{
public:
	ParentProcess();
	~ParentProcess();

	void onCreatPipe();
	std::string onPipeRead();
	void onPipeWrite(char* text);
protected:
	HANDLE hWrite;
	HANDLE hRead;
};
#endif