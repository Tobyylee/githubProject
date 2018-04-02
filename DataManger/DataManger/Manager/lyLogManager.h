#ifndef CIT_LOGMAN_H_
#define CIT_LOGMAN_H_

#include <QTextStream>
#include <QFile>

void lyOutputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif //CIT_LOGMAN_H_

