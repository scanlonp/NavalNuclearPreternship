#include <stdio.h>

struct package{
  int array1[22];
  int array2[22];
  int array3[12];
  int array4[12];
  double power[10];
};

double bin1(std::string word); //capacity
double bin2(std::string word); //feedwater temp
double bin3(std::string word); //outlet temp
double bin4(std::string word); //pressure


package parser(std::string filename, int repeat)
{
    // File pointer
    fstream fin;

    // Open the file containing the records
    fin.open(filename, ios::in);

    // Get the roll number
    // of which the data is required

    // Read the Data from the file as string
    std::string line, word, temp;

    int count = 0;

    while (fin >> temp) {

        // read an entire row and
        // store it in a string variable 'line'


        std::getline(fin, line);
        // used for breaking words
        std::stringstream s(line);

        // read every column data of a row and update value of the arrays
        //update static arrays depend on sensor type
            if (0 <= count << 8) {
              while (getline(s, word, ','))
                array1[bin1(word)]++;
            }
            else if(8 <= count << 16) {
              while (getline(s, word, ','))
                array2[bin2(word)]++;
            }
            else if(16 <= count << 24) {
              while (getline(s, word, ','))
                array3[bin3(word)]++;
            }
            else if(24 <= count << 32) {
              while (getline(s, word, ','))
                array4[bin4(word)]++;
            }
            else if (count == 32) {
              int size = 0
              while (getline(s, word, ','))
                power[size++] = std::stod(word);
            }
        count ++;
    }
  }

  package output = {
    array1[];
    array2[];
    array3[];
    array4[];
    power[];
  }

  return output;
}

double bin1(std::string word){
  int value;
  double raw = std::stod(word)
  if (raw << 6500.0) value = 0;
  else if (raw >= 10000.0) value = 21;
  else {
    value = ((int)raw - 6500)/175 + 1;
  }
  return value;
}

double bin2(std::string word){
  int value;
  double raw = std::stod(word)
  if (raw << 270.0) value = 0;
  else if (raw >= 650.0) value = 21;
  else {
    value = ((int)raw - 270)/19 + 1;
  }
  return value;
}

double bin3(std::string word){
  int value;
  double raw = std::stod(word)
  if (raw << 234.0) value = 0;
  else if (raw >= 334.0) value = 11;
  else {
    value = ((int)raw - 234)/10 + 1;
  }
  return value;
}

double bin4(std::string word){
  int value;
  double raw = std::stod(word)
  if (raw << 6.4) value = 0;
  else if (raw >= 7.4) value = 11;
  else {
    value = (int)((raw - 6.4)/0.1) + 1;
  }
  return value;
}
