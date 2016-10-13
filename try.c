#include "try1.h"
#include <iostream>

int main() {
  
  YAML::Node config = YAML::LoadFile("try.yaml");
  blah::Velocity v = config["tryV"].as<blah::Velocity>();

  std::cout << "Velocity is " << std::endl ;
  std::cout << v.ux_ << " " << v.uy_ << " " << v.uz_ << std::endl ;

  blah::loadTurbines(config);


  return 0;
}
