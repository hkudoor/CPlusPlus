runner: task scheduler runner.cpp
	g++ -std=c++11 -g -Wall -pedantic -I. runner.cpp task.o -o runner

task: task.hpp task.cpp scheduler
	g++ -std=c++11 -g -Wall -pedantic -c -I. -I../ task.cpp -o task.o

scheduler: scheduler.hpp scheduler.cpp
	g++ -std=c++11 -g -Wall -pedantic -c -I. scheduler.cpp -o scheduler.o
