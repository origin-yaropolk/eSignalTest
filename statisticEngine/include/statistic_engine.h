#pragma once

namespace StatisticEngine
{
	
class StatisticEngine : public QObject
{
	Q_OBJECT
public:
	enum State
	{
		StateStopped,
		StateWorking,
	};

public:
	static StatisticEngine* instance();

	virtual ~StatisticEngine();

public slots:
	void startCalculation(const QString& path);
	void stopCalculation();

private:
	StatisticEngine(QObject* parent = nullptr);

private:
	static StatisticEngine* s_instance;
	State m_currentState;
};

}