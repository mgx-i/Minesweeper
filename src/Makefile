# compileur
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -ansi -pedantic -std=c++14

all : run

compile : main.cpp
	$(CXX) $(CXXFLAGS) -o exec $^

run : compile
	./exec 

