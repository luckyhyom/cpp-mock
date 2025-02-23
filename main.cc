#include <iostream>
#include "Cat.h"
#include "iot.h"

int main() {
  Cat cat;
  cat.eat();
  std::cout << cat.say() << std::endl;
  return 0;
}