#include "statistic_engine.h"
#include "worker.h"

namespace StatisticEngine
{
	
StatisticEngine* StatisticEngine::s_instance = nullptr;

StatisticEngine* StatisticEngine::instance()
{
	if(!s_instance)
	{
		s_instance = new StatisticEngine();
	}

	return s_instance;
}

StatisticEngine::StatisticEngine(QObject* parent)
	: QObject(parent)
	, m_currentState(StateInitialized)
	, m_worker(new Worker())
	, m_workerThread(new QThread(this))
{
	m_worker->moveToThread(m_workerThread);

	connect(m_workerThread, SIGNAL(finished()), m_worker, SLOT(deleteLater()));
	connect(this, SIGNAL(startCalculationSignal(QString)), m_worker, SLOT(calculateStatistic(QString)));
	connect(m_worker, SIGNAL(calculationDone(QStringList)), this, SLOT(handleResults(QStringList)));

	m_workerThread->start();
}

StatisticEngine::~StatisticEngine()
{
	m_workerThread->quit();
	m_workerThread->wait();
	s_instance = nullptr;
}

void StatisticEngine::startCalculation(const QString& path)
{
	if(m_currentState == StateWorking)
	{
		stopCalculation();
	}

	m_currentState = StateWorking;
	emit stateChanged();

	emit startCalculationSignal(path);
}

void StatisticEngine::stopCalculation()
{
	m_worker->stopCalculate();
	m_currentState = StateStopped;
	emit stateChanged();
}

void StatisticEngine::handleResults(QStringList list)
{
	m_currentState = StateStopped;
	emit stateChanged();

	emit calculationsDone(list);
}

}
