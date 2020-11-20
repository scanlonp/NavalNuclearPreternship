#include <stdio.h>

void emergency(int i){
  if (i = 1)
    std::cout << "WARNING: pump capacity is too high." << std::endl;
    
  else if (i = 2)
    std::cout << "WARNING: pump capacity is too low" << std::endl;
  else if (i = 3)
    std::cout << "WARNING: intake temperatrue is too high" << std::endl;
  else if (i = 4)
    std::cout << "WARNING: intake temperatrue is too low" << std::endl;
  else if (i = 5)
    std::cout << "WARNING: outlet temperature is too high" << std::endl;
  else if (i = 6)
    std::cout << "WARNING: outlet temperature is too low" << std::endl;
  else if (i = 7)
    std::cout << "WARNING: pump pressure is too high" << std::endl;
  else if (i = 8)
    std::cout << "WARNING: pump pressure is too low" << std::endl;
  else if (i = 9)
    std::cout << "WARNING: reactor power is too high" << std::endl;
  else if (i = 10)
    std::cout << "WARNING: reactor power is too low" << std::endl;
  else
    std::cout << "EXCEPTION: emergency sequence incorrectly initated" << std::endl;
}
