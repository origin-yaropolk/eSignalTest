#pragma once

namespace eSignalTest
{
	
class ContentFrame;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);


private:
	ContentFrame* m_contentFrame;
};

}