#include <iostream>
#include "cc/my_lib/my_lib.hpp"

int main() {
  MyClass obj;
  obj.setValue(5);
  std::cout << "Value: " << obj.getValue() << std::endl;
  return 0;
}