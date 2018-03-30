#include "statistic_engine.h"

namespace StatisticEngine
{
	
StatisticEngine* StatisticEngine::s_instance = nullptr;

StatisticEngine* StatisticEngine::instance()
{
	if(!s_instance)
	{
		s_instance = new StatisticEngine();
	}

	return s_instance;
}

StatisticEngine::StatisticEngine(QObject* parent)
	: QObject(parent)
{
	
}

StatisticEngine::~StatisticEngine()
{
	s_instance = nullptr;
}

}
