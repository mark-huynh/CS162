CC=g++ -std=c++11 
EXE_FILE = gofish
HEADER = hand.hpp card.hpp deck.hpp player.hpp

all: $(EXE_FILE)

$(EXE_FILE): deck.o hand.o card.o player.o game.o gofish.cpp
	$(CC) deck.o hand.o card.o player.o game.o gofish.cpp -o $(EXE_FILE)

hand.o: $(HEADER) hand.cpp
	$(CC) -c hand.cpp

card.o: $(HEADER) card.cpp
	$(CC) -c card.cpp

deck.o: $(HEADER) deck.cpp
	$(CC) -c deck.cpp

player.o: $(HEADER) player.cpp
	$(CC) -c player.cpp

game.o: $(HEADER) game.cpp
	$(CC) -c game.cpp

clean:
	rm -f *.o $(EXE_FILE)
