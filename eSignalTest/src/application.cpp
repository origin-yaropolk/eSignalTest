#include "application.h"
#include "main_window.h"


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
	m_mainWindow.reset(new MainWindow);
}

void Application::showMainWindow()
{
	m_mainWindow->showMaximized();
}

	Application::~Application()
{
}

}
