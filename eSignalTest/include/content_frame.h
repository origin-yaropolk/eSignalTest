#pragma once

namespace eSignalTest
{

class ContentFrame : public QFrame
{
	Q_OBJECT

public:
	ContentFrame(QWidget* parent = nullptr);

	QTreeView* fileSystemTreeView() const;

public slots:
	void setInfoText(QStringList list);

private:
	QTreeView* m_fileSystemTreeView;
	QFileSystemModel* m_fileSystemTreeModel;
	QTextEdit* m_infoTextEdit;
	QSplitter* m_splitter;
};

}