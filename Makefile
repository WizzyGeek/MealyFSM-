COMPILER=g++

all:
	$(COMPILER) src/main.cpp src/MealyFSM/fsm.cpp -o build/main

clear:
	rm -rf bin
	rm -rf build
	mkdir bin && mkdir build