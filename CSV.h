#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

//This will write a single character to the CSV file
template <class T>
void writeTo(T value, std::fstream& thefile){
	thefile << value << ",";
}

void endRow(std::fstream thefile){
	thefile << "\n";
}

void writeRandom(std::fstream& thefile, double lower, double upper){
	double val;
	std::uniform_real_distribution<double> unif(lower,upper);
	std::default_random_engine re;
	val = unif(re);
	writeTo(val, thefile);
}
