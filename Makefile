CC :=g++ -std=c++20
CCFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
all: pvz.out

pvz.out: main.o system.o
	$(CC) -o pvz.out main.o system.o $(CCFLAGS) -o pvz.out

main.o: main.cpp system.hpp
	$(CC) -c main.cpp -o main.o

system.o: system.cpp system.hpp
	$(CC) -c system.cpp -o system.o

clean:
	rm *.o
	rm pvz.out
