
### makefile structure
###############################
target: dependency1 dependency2
	command
###############################

unit.o: unit.cpp unit.h
	g++ -c unit.cpp

all: unit.o target.o attacker.o
	g++ -o war_game unit.o target.o attacker.o