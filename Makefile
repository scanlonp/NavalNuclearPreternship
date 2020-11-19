# Author: Joshua Russell
# E-mail: jrusse22@nd.edu
# 
# This is the Makefile for CC5

# # G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make SorDLLTest
CSVObjs := $(OBJ)/CSV.o

CSV: $(CSVObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/CSV $(CSVObjs)
	$(EXE)/./CSV

$(OBJ)/CSV.o: $(SRC)/CSV.cpp $(INC)/CSV.h
	$(PP) $(CXXFLAGS) -c $(SRC)/CSV.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir obj exe

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
