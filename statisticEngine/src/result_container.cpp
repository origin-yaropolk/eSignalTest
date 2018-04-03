#include "result_container.h"

namespace StatisticEngine
{

ResultContainer::ResultContainer(const QString& path, QObject* parent)
	: QObject(parent)
{
	reset(path);
}

void ResultContainer::reset(const QString& path)
{
	QMutexLocker locker(&m_mutex);

	m_currentFileInfo.setFile(path);
	
	m_extensionsCount.clear();
	m_extensionsSize.clear();
	m_filesCount = 0;
	m_filesSize = 0;

	if(m_currentFileInfo.isDir())
	{
		m_type = ContainerType::DirectoryType;

		return;
	}

	if(m_currentFileInfo.isFile())
	{
		m_type = ContainerType::FileType;

		return;
	}

	m_type = ContainerType::UnexpectedType;
}

QStringList ResultContainer::getStringList() 
{
	QMutexLocker locker(&m_mutex);

	QStringList list;

	if (m_type == ContainerType::DirectoryType)
	{
		list.append(QString("Current path: %1").arg(m_currentFileInfo.absoluteFilePath()));
		list.append(QString("Files count: %1").arg(m_filesCount));
		list.append(QString("Files size: %1").arg(m_filesSize));

		list.append("Groupped by extension: ");

		foreach(auto key, m_extensionsCount.keys())
		{
			list.append(QString("for %1: %2 files").arg(key).arg(m_extensionsCount[key]));
			list.append(QString("for %1: %2 bytes").arg(key).arg(m_extensionsSize[key]));
		}

	}
	if(m_type == ContainerType::FileType)
	{
		list.append(QString("Current path: %1").arg(m_currentFileInfo.absoluteFilePath()));
		list.append(QString("File size: %1").arg(m_currentFileInfo.size()));
	}

	return list;
}

void ResultContainer::addFile(const QString& path)
{
	QMutexLocker locker(&m_mutex);

	//TODO: move this logic to worker.cpp

	QFileInfo fileInfo(path);

	assert(m_type == ContainerType::DirectoryType && fileInfo.isFile());

	m_extensionsSize[fileInfo.completeSuffix()] += fileInfo.size();
	m_extensionsCount[fileInfo.completeSuffix()]++;

	m_filesCount++;
	m_filesSize += fileInfo.size();
}

void ResultContainer::clear()
{
	
}

}
