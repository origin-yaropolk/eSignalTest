#include "application.h"

int main(int argc, char*argv[])
{
	using namespace eSignalTest;

	Application app(argc, argv);

	return app.exec();
}