#include "cc/my_lib/my_lib.hpp"

MyClass::MyClass() {
  value = 0;
}

void MyClass::setValue(int val) {
  value = val;
}

int MyClass::getValue() {
  return value;
}