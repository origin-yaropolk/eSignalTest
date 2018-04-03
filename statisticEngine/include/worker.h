#pragma once

namespace StatisticEngine
{

class ResultContainer;

class Worker : public QObject
{
	Q_OBJECT

public:
	Worker(QObject* parent = nullptr);

public slots:
	void calculateStatistic(const QString& path);
	void stopCalculate();

signals:
	void calculationDone(QStringList result);

private:
	ResultContainer* m_resultContainer;
	bool m_running;

};

}