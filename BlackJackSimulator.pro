TEMPLATE = app

QT += qml quick
CONFIG += c++11

RESOURCES += BlackJackSimulator.qrc

qml.files = BlackJackSimulator.qml

launch_modeall {
	CONFIG(debug, debug|release) {
	    DESTDIR = debug
	} else {
	    DESTDIR = release
	}
}

SOURCES += BlackJackSimulator.cpp \
           Hand.cpp \
           Shoe.cpp \
           Card.cpp \
           Player.cpp \
           Dealer.cpp \
           Rules.cpp \
           Game.cpp \
           Defs.cpp \
           Simulation.cpp \
           GameCreator.cpp

HEADERS += Card.h \
           Hand.h \
           Shoe.h \
           Constants.h \
           Player.h \
           Dealer.h \
           Rules.h \
           Defs.h \
           Game.h \
           Simulation.h \
           GameCreator.h
