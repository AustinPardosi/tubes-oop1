CC = g++
TARGET = main

all:
	$(CC) -o $(TARGET) src/Combination/*.cpp src/Card/*.cpp src/InventoryHolder/*.cpp src/CardTable/*.cpp src/DeckCard/*.cpp src/Player/*.cpp src/Command/*.cpp src/AbilityCard/*.cpp src/ExceptionHandling/*.cpp src/Game/*.cpp src/Parsing/*.cpp src/main.cpp

clean:
	rm $(TARGET)