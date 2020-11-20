#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct package{
  int array1[22];
  int array2[22];
  int array3[12];
  int array4[12];
  double power[10];
};

int bin1(std::string word); //capacity
int bin2(std::string word); //feedwater temp
int bin3(std::string word); //outlet temp
int bin4(std::string word); //pressure


package parser(std::string filename){
    // File pointer
    std::fstream fin;

    // Open the file containing the records
    fin.open(filename, std::ios::in);

    // Get the roll number
    // of which the data is required

    // Read the Data from the file as string
    std::string line, word;

    int count = 0;
    int index = 0;

    int array1[22];
    int array2[22];
    int array3[12];
    int array4[12];
    double power[10];


    while (std::getline(fin, line)) {

        // read an entire row and
        // store it in a string variable 'line'




        // used for breaking words
        std::stringstream s(line);

        // read every column data of a row and update value of the arrays
        //update static arrays depend on sensor type
            if (0 <= count || count < 8) {
              while (getline(s, word, ',')) {

                index = bin1(word);
                array1[index] += 1;
              }
            }
            else if(8 <= count || count < 16) {
              while (getline(s, word, ',')) {
                index = bin2(word);
                array2[index] += 1;
              }
            }
            else if(16 <= count || count < 24) {
              while (getline(s, word, ',')) {
                index = bin3(word);
                array3[index] += 1;
              }
            }
            else if(24 <= count || count < 32) {
              while (getline(s, word, ',')) {
                index = bin4(word);
                array4[index] += 1;
              }
            }
            else if (count == 32) {
              index = 0;
              while (getline(s, word, ',')) {
                power[index] = std::stod(word);
                ++index;
              }
            }
            else
              break;

            
        ++count;
    }


  package output;
  for (int i = 0; i < 22; i++) {
  output.array1[i] = array1[i];
  output.array2[i] = array2[i];
  }

  for (int j = 0; j < 12; j++) {
  output.array3[j] = array3[j];
  output.array4[j] = array4[j];
  }
  for (int k = 0; k < 10; k++)
  output.power[k] = power[k];


  return output;
}

int bin1(std::string word){
  int value;
  double raw = std::stod(word);
  if (raw < 6500.0) value = 0;
  else if (raw >= 10000.0) value = 21;
  else {
    value = ((int)raw - 6500)/175 + 1;
  }
  return value;
}

int bin2(std::string word){
  int value;
  double raw = std::stod(word);
  if (raw < 270.0) value = 0;
  else if (raw >= 650.0) value = 21;
  else {
    value = ((int)raw - 270)/19 + 1;
  }
  return value;
}

int bin3(std::string word){
  int value;
  double raw = std::stod(word);
  if (raw < 234.0) value = 0;
  else if (raw >= 334.0) value = 11;
  else {
    value = ((int)raw - 234)/10 + 1;
  }
  return value;
}

int bin4(std::string word){
  int value;
  double raw = std::stod(word);
  if (raw < 6.4) value = 0;
  else if (raw >= 7.4) value = 11;
  else {
    value = (int)((raw - 6.4)/0.1) + 1;
  }
  return value;
}