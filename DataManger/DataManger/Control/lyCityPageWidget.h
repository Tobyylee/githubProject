#pragma once

#include <QFrame>
#include <QPushButton>

const int g_sCityMaxCont = 35;

class lyCityPageWidget : public QFrame
{
	Q_OBJECT

public:
	lyCityPageWidget(QWidget *parent = nullptr);
	~lyCityPageWidget();

	void initWidget();
	void initSlot();
	void setData(const QVector<QString>& data);
	const QString getCityName() { return m_cityName; }

public slots:
	void onClicked();

signals:
	void currentCity(const QString&);
private:
	QPushButton* m_pushButton[g_sCityMaxCont];
	QString m_cityName;
};
