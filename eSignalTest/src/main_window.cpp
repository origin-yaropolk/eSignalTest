#include "main_window.h"
#include "content_frame.h"
#include "application.h"
#include "statistic_engine.h"

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

	 connect(m_contentFrame->fileSystemTreeView()->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex &)),
		 static_cast<Application*>(Application::instance()), SLOT(providePathToEngine(const QModelIndex&)));


	 connect(StatisticEngine::StatisticEngine::instance(), SIGNAL(calculationsDone(QStringList)),
		 m_contentFrame, SLOT(setInfoText(QStringList)));

	connect(StatisticEngine::StatisticEngine::instance(), SIGNAL(stateChanged()),
		 this, SLOT(handleStateChanged()));
}

void MainWindow::handleStateChanged()
{
	if (StatisticEngine::StatisticEngine::instance()->state() == StatisticEngine::StatisticEngine::State::StateWorking)
	{
		m_contentFrame->setInfoText({ "Calculation.." });
	}
	if (StatisticEngine::StatisticEngine::instance()->state() == StatisticEngine::StatisticEngine::State::StateInitialized)
	{
		m_contentFrame->setInfoText({ "Initialized.." });
	}
}

}
