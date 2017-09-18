#ifndef PIPECHILD_H_
#define PIPECHILD_H_

#include <Windows.h>
#include <string>
#include <QObject>

class PipeChild : public QObject
{
	Q_OBJECT
public:
	PipeChild();
	~PipeChild();

	void OnInitialUpdate();
	std::string  onPipeRead();
	void onPipeWrite(char* text);

signals:
	void sendReadData(std::string data);
protected:
	HANDLE hWrite;
	HANDLE hRead;
};
#endif