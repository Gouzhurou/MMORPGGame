.PHONY: all clean

all: main.o BombEvent.o TeleportEvent.o TotemEvent.o Controller.o Game.o GameTracker.o Apple.o Bag.o Cell.o Character.o Field.o Level.o Point.o Ring.o ConsoleFieldPrinter.o KeyboardInput.o FieldGenerator.o FileReader.o
	g++ main.o BombEvent.o TeleportEvent.o TotemEvent.o Controller.o Game.o GameTracker.o Apple.o Bag.o Cell.o Character.o Field.o Level.o Point.o Ring.o ConsoleFieldPrinter.o KeyboardInput.o FieldGenerator.o FileReader.o -o hello

main.o: main.cpp h/logic/Game.h
	g++ -c main.cpp

Game.o: cpp/logic/Game.cpp h/logic/Game.h h/logic/enum/GameState.h h/util/FileReader.h h/util/InputAction.h h/util/FieldGenerator.h h/util/impl/ConsoleFieldPrinter.h h/logic/GameTracker.h
	g++ -c cpp/logic/Game.cpp

BombEvent.o: cpp/event/impl/BombEvent.cpp h/event/impl/BombEvent.h h/event/GameEvent.h
	g++ -c cpp/event/impl/BombEvent.cpp

TeleportEvent.o: cpp/event/impl/TeleportEvent.cpp h/event/impl/TeleportEvent.h h/event/GameEvent.h h/logic/enum/Direction.h
	g++ -c cpp/event/impl/TeleportEvent.cpp

TotemEvent.o: cpp/event/impl/TotemEvent.cpp h/event/impl/TotemEvent.h h/event/GameEvent.h
	g++ -c cpp/event/impl/TotemEvent.cpp

Controller.o: cpp/logic/Controller.cpp h/logic/Controller.h h/model/Character.h h/model/Field.h
	g++ -c cpp/logic/Controller.cpp

GameTracker.o: cpp/logic/GameTracker.cpp h/logic/GameTracker.h h/logic/Controller.h h/util/FieldPrinter.h h/util/impl/KeyboardInput.h
	g++ -c cpp/logic/GameTracker.cpp

Apple.o: cpp/model/Apple.cpp h/model/Apple.h
	g++ -c cpp/model/Apple.cpp

Bag.o: cpp/model/Bag.cpp h/model/Bag.h h/model/Apple.h h/model/Ring.h
	g++ -c cpp/model/Bag.cpp

Cell.o: cpp/model/Cell.cpp h/model/Cell.h h/event/GameEvent.h
	g++ -c cpp/model/Cell.cpp

Character.o: cpp/model/Character.cpp h/model/Character.h h/model/Level.h h/model/Bag.h
	g++ -c cpp/model/Character.cpp

Field.o: cpp/model/Field.cpp h/model/Field.h h/model/Cell.h h/model/Point.h
	g++ -c cpp/model/Field.cpp

Level.o: cpp/model/Level.cpp h/model/Level.h
	g++ -c cpp/model/Level.cpp

Point.o: cpp/model/Point.cpp h/model/Point.h h/logic/enum/Direction.h
	g++ -c cpp/model/Point.cpp

Ring.o: cpp/model/Ring.cpp h/model/Ring.h h/model/enum/RingType.h
	g++ -c cpp/model/Ring.cpp

ConsoleFieldPrinter.o: cpp/util/impl/ConsoleFieldPrinter.cpp h/util/impl/ConsoleFieldPrinter.h h/util/FieldPrinter.h h/event/impl/BombEvent.h h/event/impl/TotemEvent.h h/event/impl/TeleportEvent.h
	g++ -c cpp/util/impl/ConsoleFieldPrinter.cpp

KeyboardInput.o: cpp/util/impl/KeyboardInput.cpp h/util/impl/KeyboardInput.h h/util/InputAction.h
	g++ -c cpp/util/impl/KeyboardInput.cpp

FieldGenerator.o: cpp/util/FieldGenerator.cpp h/util/FieldGenerator.h h/logic/Controller.h h/event/impl/BombEvent.h h/event/impl/TotemEvent.h h/event/impl/TeleportEvent.h
	g++ -c cpp/util/FieldGenerator.cpp

FileReader.o: cpp/util/FileReader.cpp h/util/FileReader.h h/util/enum/Command.h
	g++ -c cpp/util/FileReader.cpp

clean:
	del *.o hello.exe
