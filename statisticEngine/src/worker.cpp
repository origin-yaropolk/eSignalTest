#include "worker.h"
#include "result_container.h"

namespace StatisticEngine
{

Worker::Worker(QObject* parent)
	: QObject(parent)
	, m_resultContainer(new ResultContainer(QDir::rootPath(), this))
	, m_running(false)
{
}

void Worker::calculateStatistic(const QString& path)
{
	m_running = true;

	QDir dir(path);

	if(dir == QDir::rootPath())
	{
		return;
	}

	m_resultContainer->reset(path);

	QFileInfoList list = dir.entryInfoList(QDir::Dirs);

	QDirIterator dirIterator(dir.path(), QDir::Files, QDirIterator::Subdirectories);
	while(dirIterator.hasNext() && m_running)
	{
		m_resultContainer->addFile(dirIterator.next());
	}

	m_running = false;
	emit calculationDone(m_resultContainer->getStringList());
}

void Worker::stopCalculate()
{
	m_running = false;
}

}

