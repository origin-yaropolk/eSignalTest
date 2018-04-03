#include "content_frame.h"

namespace eSignalTest
{
	
ContentFrame::ContentFrame(QWidget* parent)
	: QFrame(parent)
	, m_fileSystemTreeView(new QTreeView(this))
	, m_fileSystemTreeModel(new QFileSystemModel(this))
	, m_infoTextEdit(new QTextEdit(this))
	, m_splitter(new QSplitter(this))
{
	QHBoxLayout* layout = new QHBoxLayout(this);

	m_splitter->setOrientation(Qt::Horizontal);
	m_splitter->setChildrenCollapsible(false);

	m_splitter->addWidget(m_fileSystemTreeView);
	m_splitter->addWidget(m_infoTextEdit);
	layout->addWidget(m_splitter);
	setLayout(layout);

	m_fileSystemTreeModel->setRootPath(QDir::rootPath());
	m_fileSystemTreeView->setModel(m_fileSystemTreeModel);
}

QTreeView* ContentFrame::fileSystemTreeView() const
{
	return m_fileSystemTreeView;
}

void ContentFrame::setInfoText(QStringList list)
{
	m_infoTextEdit->clear();
	foreach(auto string, list)
	{
		m_infoTextEdit->append(string);
	}
}

}
