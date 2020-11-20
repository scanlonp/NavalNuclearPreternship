//Parker Scanlon
//pscanlo2@nd.edu

// filter function for preternship Fall 2020

#include "parser.cpp"
#include "emergency.cpp"

#define CAPACITYBIN 175.0
#define TEMP1BIN 19.0
#define TEMP2BIN 10.0
#define PRESUREBIN 0.1



/*
*
* inputs:
*
*   sensorBins => struct of the most recent values read from the sensors (of doubles) [passed by ref]
*   output => double array to store the representative values [passed by ref]
*
* outputs:
*   none
*   function writes into output as it is passed by ref
*
*/

void filter(package& sensorBins, double (&output)[5]) {
  double total = 0;
  int num = 0;
  int i = 0;

  // pump capacity
  // 6500 - 10000


    if (sensorBins.array1[21] > 5) {
      emergency(1);
    }
    else if (sensorBins.array1[0] > 5) {
      emergency(2);
    }

    else {
      num = 5;
      for (i = 1; i < 21; ++i) {
        if (num > 0) {
          if (sensorBins.array1[i] > 0) {
            --sensorBins.array1[i];
            --num;
          }
        }
      }

      num = 5;
      for (i = 20; i > 0; --i) {
        if (num > 0) {
          if (sensorBins.array1[i] > 0) {
            --sensorBins.array1[i];
            --num;
          }
        }
      }

      total = 0;
      for (i = 1; i < 21; ++i) {
        total += sensorBins.array1[i] * i * CAPACITYBIN;
      }

      total /= (75.0 - (sensorBins.array1[0] + sensorBins.array1[21]));

      output[0] = total;
    }



    //feed water temp
    // 270 - 650

    if (sensorBins.array2[21] > 5) {
      emergency(3);
    }
    else if (sensorBins.array2[0] > 5) {
      emergency(4);
    }

    else {
      num = 5;
      for (i = 1; i < 21; ++i) {
        if (num > 0) {
          if (sensorBins.array2[i] > 0) {
            --sensorBins.array2[i];
            --num;
          }
        }
      }

      num = 5;
      for (i = 20; i > 0; --i) {
        if (num > 0) {
          if (sensorBins.array2[i] > 0) {
            --sensorBins.array2[i];
            --num;
          }
        }
      }

      total = 0;
      for (i = 1; i < 21; ++i) {
        total += sensorBins.array2[i] * i * TEMP1BIN;
      }

      total /= (75.0 - (sensorBins.array2[0] + sensorBins.array2[21]));

      output[1] = total;
    }



    // outlet temp
    // 234 - 334


    if (sensorBins.array3[11] > 5) {
      emergency(5);
    }
    else if (sensorBins.array3[0] > 5) {
      emergency(6);
    }

    else {
      num = 5;
      for (i = 1; i < 11; ++i) {
        if (num > 0) {
          if (sensorBins.array3[i] > 0) {
            --sensorBins.array3[i];
            --num;
          }
        }
      }

      num = 5;
      for (i = 10; i > 0; --i) {
        if (num > 0) {
          if (sensorBins.array3[i] > 0) {
            --sensorBins.array3[i];
            --num;
          }
        }
      }

      total = 0;
      for (i = 1; i < 11; ++i) {
        total += sensorBins.array3[i] * i * TEMP2BIN;
      }

      total /= (75.0 - (sensorBins.array3[0] + sensorBins.array3[11]));

      output[2] = total;
    }


    // presure
    // 6.4 - 7.4

    if (sensorBins.array4[11] > 5) {
      emergency(7);
    }
    else if (sensorBins.array4[0] > 5) {
      emergency(8);
    }

    else {
      num = 5;
      for (i = 1; i < 11; ++i) {
        if (num > 0) {
          if (sensorBins.array4[i] > 0) {
            --sensorBins.array4[i];
            --num;
          }
        }
      }

      num = 5;
      for (i = 10; i > 0; --i) {
        if (num > 0) {
          if (sensorBins.array4[i] > 0) {
            --sensorBins.array4[i];
            --num;
          }
        }
      }

      total = 0;
      for (i = 1; i < 11; ++i) {
        total += sensorBins.array4[i] * i * PRESUREBIN;
      }

      total /= (75.0 - (sensorBins.array4[0] + sensorBins.array4[11]));

      output[3] = total;
    }



    // power
    // 20 - 100

    int low = 0;
    int high = 0;

    for (i = 0; i < 10; ++i) {
      
      if (sensorBins.power[i] < 20) {
        low += 1;
      }
      else if (sensorBins.power[i] > 100) {
        high += 1;
      }
    }

    if (low > 0) {
      emergency(10);
    }
    else if (high > 1) {
       emergency(9);
    }
    else {
      total = 0;
      for (i = 0; i < 10; ++i) {
        total += sensorBins.power[i];
      }
      total /= 10;
      output[4] = total;
    }

}
