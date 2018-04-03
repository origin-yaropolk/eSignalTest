#pragma once

namespace StatisticEngine
{

class Worker;
	
class StatisticEngine : public QObject
{
	Q_OBJECT

public:
	enum State
	{
		StateInitialized,
		StateStopped,
		StateWorking,
	};

public:
	static StatisticEngine* instance();

	virtual ~StatisticEngine();

	State state()
	{
		return m_currentState;
	}

public slots:
	void startCalculation(const QString& path);
	void stopCalculation();
	void handleResults(QStringList path);

signals:
	void startCalculationSignal(const QString& path);
	void calculationsDone(QStringList);
	void stateChanged();

private:
	StatisticEngine(QObject* parent = nullptr);

private:
	static StatisticEngine* s_instance;
	State m_currentState;
	Worker* m_worker;
	QThread* m_workerThread;
};

}