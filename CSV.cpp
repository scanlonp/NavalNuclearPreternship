#include "../include/CSV.h"
#include <fstream>
#include <random>

#define COUT std::cout
#define ENDL std::endl
#define CIN std::cin

int main(){
	std::fstream thefile;
	long unsigned int numCols;
	double lower;
	double upper;
	std::string fileName;
	COUT << "Enter the file name: ";
	CIN >> fileName;
	COUT << ENDL;
	numCols = 10;
	thefile.open(fileName);
	for(int j = 0; j < 8; ++j){ 

		lower = 6500;
		upper = 10000;
		for(unsigned int i = 0; i < numCols; ++i){
			double val;
			val = ((double)rand() / RAND_MAX) * (upper - lower) +lower;
			thefile << val << ",";
		}
		thefile << "\n";
		
		lower = 270;
		upper = 650;
		for(unsigned int i = 0; i < numCols; ++i){
			double val;
			val = ((double)rand() / RAND_MAX) * (upper - lower) +lower;
			thefile << val << ",";
		}
		thefile << "\n";

		lower = 270;
		upper = 650;
		for(unsigned int i = 0; i < numCols; ++i){
			double val;
			val = ((double)rand() / RAND_MAX) * (upper - lower) +lower;
			thefile << val << ",";
		}
		thefile << "\n";

		
		lower = 6.4;
		upper = 7.4;
		for(unsigned int i = 0; i < numCols; ++i){
			double val;
			val = ((double)rand() / RAND_MAX) * (upper - lower) +lower;
			thefile << val << ",";
		}
		thefile << "\n";

	}
	
	lower = 20;
	upper = 100;
	for(unsigned int i = 0; i < numCols; ++i){
		double val;
		val = ((double)rand() / RAND_MAX) * (upper - lower) +lower;
		thefile << val << ",";
	}
	thefile << "\n";
	
	thefile.close();
}
