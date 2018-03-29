#include "main_window.h"
#include "content_frame.h"

namespace eSignalTest
{

 MainWindow::MainWindow(QWidget* parent)
	 : QMainWindow(parent)
	, m_contentFrame(new ContentFrame(this))
{
	 auto layout = new QVBoxLayout(this);
	 layout->addWidget(m_contentFrame);
	 QWidget* centralWidget = new QWidget(this);
	 centralWidget->setLayout(layout);
	 setCentralWidget(centralWidget);
}

}