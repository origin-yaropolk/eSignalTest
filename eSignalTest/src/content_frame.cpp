#include "content_frame.h"

namespace eSignalTest
{
	
ContentFrame::ContentFrame(QWidget* parent)
	: QFrame(parent)
	, m_fileSystemTreeView(new QTreeView(this))
	, m_fileSystemTreeModel(new QFileSystemModel(this))
	, m_infoLabel(new QLabel(this))
	, m_splitter(new QSplitter(this))
{
	QHBoxLayout* layout = new QHBoxLayout(this);

	m_splitter->setOrientation(Qt::Horizontal);
	m_splitter->setChildrenCollapsible(false);

	m_splitter->addWidget(m_fileSystemTreeView);
	m_splitter->addWidget(m_infoLabel);
	layout->addWidget(m_splitter);
	setLayout(layout);

	m_fileSystemTreeModel->setRootPath(QDir::currentPath());
	m_fileSystemTreeView->setModel(m_fileSystemTreeModel);

	connect(m_fileSystemTreeView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex &)), 
		this, SLOT(setInfoText(const QModelIndex&)));
}

void ContentFrame::setInfoText(const QModelIndex& index)
{
	m_infoLabel->setText(index.data(QFileSystemModel::FilePathRole).toString());
}

}
