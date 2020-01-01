//#include <QGuiApplication>
//#include <QQmlApplicationEngine>

#include "Simulation.h"
#include "GameCreator.h"
#include <memory>

#include <iostream>

int main(int argc, char *argv[]) {
	const int kIterations = 100;
	const int kShoesPerIteration = 100;

	GameCreator creator;

	std::unique_ptr<Game> game = creator.OtherPoorPlayerInterference();

	Simulation simulation(kIterations, kShoesPerIteration, game.get());
	simulation.Start();

//	creator.PureBasicStrategy();
//	creator.ComparePerfectPlayers();
//	creator.OtherPerfectPlayerInterference();
//	creator.OtherAveragePlayerInterference();
//	creator.OtherPoorPlayerInterference();

//	QGuiApplication app(argc, argv);
//	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/BlackJackSimulator.qml")));
//	return app.exec();
	return 0;
}
