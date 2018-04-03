#include "application.h"
#include "main_window.h"
#include "statistic_engine.h"

namespace eSignalTest
{

Application::Application(int& argc, char* argv[])
	: QApplication(argc, argv)
{
	initialize();

	showMainWindow();
}

void Application::initialize()
{
	m_statisticEngine = StatisticEngine::StatisticEngine::instance();

	m_mainWindow.reset(new MainWindow);
}

void Application::showMainWindow()
{
	m_mainWindow->showMaximized();
}

Application::~Application()
{
}

StatisticEngine::StatisticEngine* Application::statisticEngine()
{
	return m_statisticEngine;
}

void Application::providePathToEngine(const QModelIndex& index)
{
	m_statisticEngine->startCalculation(index.data(QFileSystemModel::FilePathRole).toString());
}

}
