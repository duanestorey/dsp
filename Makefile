default: build

dsp.o: dsp.cpp
	g++ -c dsp.cpp

main.o: main.cpp dsp.h
	g++ -c main.cpp

build: dsp.o main.o
	g++ -o dsp dsp.o main.o
