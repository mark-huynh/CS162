CC = g++ -std=c++11
EXEC = zoogame
HEADER = animal.hpp sloth.hpp seaotter.hpp monkey.hpp zoo.hpp

all: $(EXEC)

$(EXEC) : animal.o sloth.o monkey.o zoo.o main.cpp seaotter.o
	$(CC) animal.o sloth.o monkey.o zoo.o main.cpp seaotter.o -o $(EXEC)

animal.o: animal.cpp $(HEADER)
	$(CC) -c animal.cpp

sloth.o: sloth.cpp $(HEADER)
	$(CC) -c sloth.cpp

monkey.o: monkey.cpp $(HEADER)
	$(CC) -c monkey.cpp

zoo.o: zoo.cpp $(HEADER)
	$(CC) -c zoo.cpp

seaotter.o: seaotter.cpp $(HEADER)
	$(CC) -c seaotter.cpp

clean:
	rm -f *.o $(EXEC)
