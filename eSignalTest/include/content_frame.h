#pragma once

namespace eSignalTest
{

class ContentFrame : public QFrame
{
	Q_OBJECT

public:
	ContentFrame(QWidget* parent = nullptr);

private slots:
	void setInfoText(const QModelIndex& index);

private:
	QTreeView* m_fileSystemTreeView;
	QFileSystemModel* m_fileSystemTreeModel;
	QLabel* m_infoLabel;
	QSplitter* m_splitter;
};

}