
### makefile structure
###############################
target: dependency1 dependency2
	command
###############################

unit.o: unit.cpp unit.h
	g++ -c unit.cpp

target.o: target.cpp target.h
	g++ -c target.cpp
	
attecker.o: attacker.cpp attacker.h
	g++ -c attacker.cpp
	
all: unit.o attacker.o target.o
	g++ war_game.cpp -o war_game attacker.o target.o unit.o
	
clean:
	rm *.o *.exe
