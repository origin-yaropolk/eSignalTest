#pragma once

namespace StatisticEngine
{

enum ContainerType
{
	DirectoryType,
	FileType,
	UnexpectedType
};

class ResultContainer : public QObject
{
	Q_OBJECT

public:
	ResultContainer(const QString& path, QObject* parent = nullptr);

	void reset(const QString& path);
	void addFile(const QString& path);
	QStringList getStringList() ;

signals:
	void infoAdded();
	void cleared();

private:
	void clear();

private:
	QFileInfo m_currentFileInfo;
	ContainerType m_type;
	QMap<QString, int> m_extensionsCount;
	QMap<QString, quint64> m_extensionsSize;
	int m_filesCount;
	quint64 m_filesSize;

	QMutex m_mutex;
};

}