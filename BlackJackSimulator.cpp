//#include <QGuiApplication>
//#include <QQmlApplicationEngine>

#include "Simulation.h"
#include "GameCreator.h"
#include <memory>

#include <iostream>

#include <chrono>
#include <thread>
#include <vector>
#include <numeric>

void func(int i) {
	std::this_thread::sleep_for (std::chrono::seconds(i));
}

int main(int argc, char *argv[]) {
	const int kIterations = 500;
	const int kShoesPerIteration = 250;

//	std::unique_ptr<Game> game;
//
//	// make sure game is completely independent of the creator
//	{
//		GameCreator creator;
//		game = std::move(creator.OtherPoorPlayerInterference());
//	}
//
//	// could insert any other type of game (can be a game assembled through future ui)
//	Simulation simulation(kIterations, kShoesPerIteration, game.get());
//	simulation.Start();

	GameCreator creator;
	Simulation simulation(kIterations, kShoesPerIteration, &creator);
	simulation.StartMultiThreaded();



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
