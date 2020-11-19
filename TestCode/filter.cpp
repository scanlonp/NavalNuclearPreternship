//Parker Scanlon
//pscanlo2@nd.edu

// filter function for preternship Fall 2020

#include <vector>

#define VECTOR std::vector


/*
*
* inputs:
*   filteredData => array of dynamic arrays (of doubles?) [passed by ref]
*   sensorBins => 2d array of the most recent values read from the sensors (of doubles?) [passed by ref]
*   sensorMultiplier => array of weights for each sensor (of doubles?) (converts from the bin number to the representative value) [passed by ref]
*
* outputs:
*   none
*   function writes into the filteredData as it is passed by ref
*
*/

void filter(VECTOR<double> (&filteredData)[10], double (&sensorBins)[10][22], double (&sensorMultiplier)[10]) {
  for (int i = 0; i < 22; ++i) {
    if (sensorBins[i][0] > 5 || sensorBins[i][21] > 5) {
      // goto Emergency
    }

    else {
      int num = 5;
      for (int j = 1; j < 21; ++j) {
        if (num > 0) {
          if (sensorBins[i][j] > 0) {
            --sensorBins[i][j];
            --num;
          }
        }
      }

      num = 5;
      for (j = 20; j > 0; --j) {
        if (num > 0) {
          if (sensorBins[i][j] > 0) {
            --sensorBins[i][j];
            --num;
          }
        }
      }

      double total = 0;
      for (j = 1; j < 21; ++j) {
        total += sensorBins[i][j] * j * sensorMultiplier[i];
      }

      total /= (50 - (sensorBins[i][0] + sensorBins[i][21]));

      filteredData[i].push_back(total);
    }
  }
}
