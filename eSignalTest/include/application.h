#pragma once

namespace eSignalTest
{

class MainWindow;

class Application : public QApplication
{
	Q_OBJECT

public:
	Application(int& argc, char* argv[]);
	~Application();

private:
	void initialize();
	void showMainWindow();

private:
	std::unique_ptr<MainWindow> m_mainWindow;
};

}