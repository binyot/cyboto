#include <iostream>
#include "base_components_manager.h"
#include <chrono>
#include <ctime>

// TODO implement logger
// TOTO doxigen doc

int main() {

  time_t my_time = time(NULL);
  std::cout << "run done at: " << ctime(&my_time) << std::endl;
}
