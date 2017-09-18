#include "ParentProcess.h"
#include <iostream>
#include <QDebug>
#include <QDateTime>

ParentProcess::ParentProcess()
{
	hRead = nullptr;
	hWrite = nullptr;
}

ParentProcess::~ParentProcess()
{
	if(hRead)
	{
		CloseHandle(hRead);
	}
	if(hWrite)
	{
		CloseHandle(hWrite);
	}
}

void ParentProcess::onCreatPipe()
{
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	if(!CreatePipe(&hRead, &hWrite, &sa, 0))
	{
		//	MessageBox("创建匿名管道失败！");
		std::cout<<"Creat pipe fail！";
		return;
	}

	STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	ZeroMemory(&sui, sizeof(STARTUPINFO));
	sui.cb = sizeof(STARTUPINFO);
	sui.dwFlags = STARTF_USESTDHANDLES;
	sui.hStdInput = hRead;
	sui.hStdOutput = hWrite;
	sui.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	if(!CreateProcess(TEXT("D:\\project\\TestPipeChild\\Win32\\Debug\\TestPipeChild.exe"), NULL, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &sui, &pi))
	{
		CloseHandle(hRead);
		CloseHandle(hWrite);
		hRead = NULL;
		hWrite = NULL;
		std::cout<<"Create Thread fail！";
		//		MessageBox("创建子线程失败！");
		return;
	}
	else
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

std::string ParentProcess::onPipeRead()
{
	char buf[1000];
	DWORD dwRead;
	DWORD dwRead2;
	DWORD dwRead3;
	//我用的是PeekNamedPipe，而不是ReadFile，因为如果管道没有数据的话，ReadFile会阻塞线程
	PeekNamedPipe(hRead, buf, 1000, &dwRead, &dwRead2, &dwRead3);
	std::string l_str = "read fail";
	if(dwRead <= 0)
	{
		return l_str;
	}
	if(!ReadFile(hRead, buf, 1000, &dwRead, NULL))
	{
		return l_str;
	}
//	std::string l_str = buf;
	//注意char数组遇到'\0'字符串显示停止的问题（数据没变化，只是字符串遇到会只显示开始到结束符之间的字符，之后的字符就不显示），
	//其实数组长度不止，所以每次连续发送几次，字符串显示收到的总是一条
	//其实是遇到此问题，下面对'\0'进行处理
	int count = 0;
	for(int i=0; i<dwRead; i++)
	{
		if(buf[i] != '\0')
		{
			buf[i-count] = buf[i];
		}
		else
		{
			count++;
			//buf[i] = ' ';
		}
	}
	qDebug()<<"onPipeRead"<<buf;
	return buf;
}

void ParentProcess::onPipeWrite(char*  text)
{
	DWORD dwWrite;
	std::string l_str = text;
	
	//QString使用toStdString方法转成string再使用此string转成char*，在使用WriteFile方法时候会出现内存对其问题！！会崩溃
	//要使用.toLatin1().data()转成char*
	/*QString l_qstr = "asf";
	l_str = l_qstr.toStdString();*/
	qDebug()<<"l_str"<<QString::fromStdString(	l_str)<<"length"<<l_str.length()+1;
	if(!WriteFile(hWrite, text, l_str.length()+1, &dwWrite, NULL))
	{
		qDebug()<<"Write data fail！";
		return;
	}
}
