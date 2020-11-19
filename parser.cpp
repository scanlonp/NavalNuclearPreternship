#include <stdio.h>

struct package{
  int array1[size1];
  int array2[size2];
  int array3[size3];
  int array4[size4];
};

int bin1(std::string word);
int bin2(std::string word);
int bin3(std::string word);
int bin4(std::string word);


package* parser(std::string filename, int repeat)
{
    // File pointer
    fstream fin;

    // Open the file containing the records
    fin.open(filename, ios::in);

    // Get the roll number
    // of which the data is required

    // Read the Data from the file as String Vector
    vector<std::string> row;
    std::string line, word, temp;


  //Here's the function to read and update a single file, still need to finalize how to traverse through the file
    int count = 0
    while (fin >> temp) {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        for (i=0; i< maxline; i++) {

        getline(fin, line);
        // used for breaking words
        std::stringstream s(line);

        // read every column data of a row and update value of the arrays
        //update static arrays depend on sensor type
            if (a <= i < b) {
              while (getline(s, word, ','))
              array1[bin1(word)]++;
            }
            else if(b <= i < c) {
              while (getline(s, word, ','))
              array2[bin2(word)]++;
            }
            else if(c <= i < d) {
              while (getline(s, word, ','))
              array3[bin3(word)]++;
            }
            else {
              while (getline(s, word, ','))
              array4[bin4(word)]++;
            }
        }
    }
  }

  package* output = {
    array1[];
    array2[];
    array3[];
    array4[];
  }

  return output
}
