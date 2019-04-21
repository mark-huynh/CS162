CC = g++ -std=c++11 -g
HEADER = event.hpp wumpus.hpp gold.hpp pit.hpp spawn.hpp room.hpp map.hpp bats.hpp game.hpp
EXEC = huntTheWumpus

all: $(EXEC)


$(EXEC): wumpus.o main.cpp gold.o spawn.o pit.o bats.o room.o map.o game.o
	$(CC) wumpus.o main.cpp gold.o spawn.o pit.o bats.o room.o map.o game.o -o $(EXEC)

wumpus.o: wumpus.cpp $(HEADER)
	$(CC) -c wumpus.cpp

gold.o: gold.cpp $(HEADER)
	$(CC) -c gold.cpp

spawn.o: spawn.cpp $(HEADER)
	$(CC) -c spawn.cpp

pit.o: pit.cpp $(HEADER)
	$(CC) -c pit.cpp

bats.o: bats.cpp $(HEADER)
	$(CC) -c bats.cpp

room.o: room.cpp $(HEADER)
	$(CC) -c room.cpp

map.o: map.cpp $(HEADER)
	$(CC) -c map.cpp

game.o: game.cpp $(HEADER)
	$(CC) -c game.cpp


clean:
	rm -f *.o $(EXEC)
