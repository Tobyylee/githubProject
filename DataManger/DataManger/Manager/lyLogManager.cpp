#include "lyLogManager.h"
#include <QDateTime>

void lyOutputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QString text;
	switch(type) 
	{
	case QtDebugMsg:
		text = QString("Debug:");
		break;

	case QtWarningMsg:
		text = QString("Warning:");
		break;

	case QtCriticalMsg:
		text = QString("Critical:");
		break;

	case QtFatalMsg:
		text = QString("Fatal:");
	}
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	QString message = QString("(%1) ").arg(current_date).append(text).append(msg);

	QFile file("log.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream<<message<<"\r\n";
	file.close();
}
