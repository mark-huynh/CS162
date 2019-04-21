CC = g++ -std=c++11 -g
EXEC = EscapeCS162
HEADER = wall.hpp	instructor.hpp intrepidstudent.hpp mazelevel.hpp mazelocation.hpp ta.hpp mazeperson.hpp openspace.hpp maze.hpp

all: $(EXEC)

$(EXEC) : main.cpp wall.o	instructor.o intrepidstudent.o mazelevel.o ta.o mazeperson.o openspace.o maze.o
	$(CC) main.cpp wall.o	instructor.o intrepidstudent.o mazelevel.o ta.o mazeperson.o openspace.o maze.o -o $(EXEC)


wall.o : wall.cpp $(HEADER)
	$(CC) -c wall.cpp

instructor.o : instructor.cpp $(HEADER)
	$(CC) -c instructor.cpp

intrepidstudent.o : intrepidstudent.cpp $(HEADER)
	$(CC) -c intrepidstudent.cpp

mazelevel.o : mazelevel.cpp $(HEADER)
	$(CC) -c mazelevel.cpp

ta.o : ta.cpp $(HEADER)
	$(CC) -c ta.cpp

mazeperson.o : mazeperson.cpp $(HEADER)
	$(CC) -c mazeperson.cpp

openspace.o : openspace.cpp $(HEADER)
	$(CC) -c openspace.cpp

maze.o : maze.cpp $(HEADER)
	$(CC) -c maze.cpp


clean:
	rm -f *.o $(EXEC)
