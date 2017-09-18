#include "PipeChild.h"
#include <iostream>
#include <QDebug>

PipeChild::PipeChild()
{
	hRead = NULL;
	hWrite = NULL;
}

PipeChild::~PipeChild()
{
	if(!hRead)
	{
		CloseHandle(hRead);
	}
	if(!hWrite)
	{
		CloseHandle(hWrite);
	}
}

void PipeChild::OnInitialUpdate()
{
	hRead = GetStdHandle(STD_INPUT_HANDLE);
	hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
}

std::string PipeChild::onPipeRead()
{
	char buf[100];
	DWORD dwRead;
	DWORD dwRead2;
	DWORD dwRead3;
	//用的是PeekNamedPipe，而不是ReadFile，因为如果管道没有数据的话，ReadFile会阻塞线程
	PeekNamedPipe(hRead, buf, 100, &dwRead, &dwRead2, &dwRead3);
	std::string l_str = "read fail";
	if(dwRead <= 0)
	{
		return l_str;
	}
	if(!ReadFile(hRead, buf, 100, &dwRead, NULL))
	{
		return l_str;
	}
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
	qDebug()<<"buf onPipeRead"<<buf;
	return buf;
}

void PipeChild::onPipeWrite(char* text)
{
	DWORD dwWrite;
	std::string l_str = text;
	if(!WriteFile(hWrite, text, l_str.length()+1, &dwWrite, NULL))
	{
		std::cout<<"write data fail！";
		return;
	}
}
