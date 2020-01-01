//#include <QGuiApplication>
//#include <QQmlApplicationEngine>

#include "Simulation.h"

int main(int argc, char *argv[]) {
	const int kIterations = 100;
	const int kShoesPerIteration = 100;

	Simulation simulation(kIterations, kShoesPerIteration);
	simulation.ComparePlayerQuality();

//	simulation.PureBasicStrategy();
//	simulation.ComparePerfectPlayers();
//	simulation.OtherPerfectPlayerInterference();
//	simulation.OtherAveragePlayerInterference();
//	simulation.OtherPoorPlayerInterference();

//	QGuiApplication app(argc, argv);
//	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/BlackJackSimulator.qml")));
//	return app.exec();
	return 0;
}
