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
		//	MessageBox("���������ܵ�ʧ�ܣ�");
		std::cout<<"Creat pipe fail��";
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
		std::cout<<"Create Thread fail��";
		//		MessageBox("�������߳�ʧ�ܣ�");
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
	//���õ���PeekNamedPipe��������ReadFile����Ϊ����ܵ�û�����ݵĻ���ReadFile�������߳�
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
	//ע��char��������'\0'�ַ�����ʾֹͣ�����⣨����û�仯��ֻ���ַ���������ֻ��ʾ��ʼ��������֮����ַ���֮����ַ��Ͳ���ʾ����
	//��ʵ���鳤�Ȳ�ֹ������ÿ���������ͼ��Σ��ַ�����ʾ�յ�������һ��
	//��ʵ�����������⣬�����'\0'���д���
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
	
	//QStringʹ��toStdString����ת��string��ʹ�ô�stringת��char*����ʹ��WriteFile����ʱ�������ڴ�������⣡�������
	//Ҫʹ��.toLatin1().data()ת��char*
	/*QString l_qstr = "asf";
	l_str = l_qstr.toStdString();*/
	qDebug()<<"l_str"<<QString::fromStdString(	l_str)<<"length"<<l_str.length()+1;
	if(!WriteFile(hWrite, text, l_str.length()+1, &dwWrite, NULL))
	{
		qDebug()<<"Write data fail��";
		return;
	}
}
