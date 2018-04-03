#pragma once
#include "statistic_engine.h"

namespace  StatisticEngine
{
	class StatisticEngine;
}

namespace eSignalTest
{
	
class ContentFrame;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

public slots:
	void handleStateChanged();

private:
	ContentFrame* m_contentFrame;
};

}
