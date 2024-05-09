CC := g++ -std=c++20
CCFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
all: pvz.out

pvz.out: main.o system.o plant.o utilities.o projectile.o
	$(CC) -o pvz.out main.o system.o plant.o utilities.o projectile.o $(CCFLAGS) -o pvz.out

main.o: main.cpp system.hpp
	$(CC) -c main.cpp -o main.o

system.o: system.cpp system.hpp plant.cpp plant.hpp
	$(CC) -c system.cpp -o system.o

plant.o: plant.cpp plant.hpp projectile.cpp
	$(CC) -c plant.cpp -o plant.o

utilities.o: utilities.cpp utilities.hpp
	$(CC) -c utilities.cpp -o utilities.o

projectile.o: projectile.cpp projectile.hpp utilities.cpp
	$(CC) -c projectile.cpp -o projectile.o

clean:
	rm *.o
	rm pvz.out
