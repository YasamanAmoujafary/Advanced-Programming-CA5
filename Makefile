CC := g++ -std=c++20
CCFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
all: pvz.out

pvz.out: main.o system.o plant.o
	$(CC) -o pvz.out main.o system.o plant.o $(CCFLAGS) -o pvz.out

main.o: main.cpp system.hpp
	$(CC) -c main.cpp -o main.o

system.o: system.cpp system.hpp plant.cpp plant.hpp
	$(CC) -c system.cpp -o system.o

plant.o: plant.cpp plant.hpp
	$(CC) -c plant.cpp -o plant.o

clean:
	rm *.o
	rm pvz.out
