// Copyright 2021 DB

#include <iostream>

#include "TimedDoor.h"

int main() {
  TimedDoor door(2);
  try {
    door.unlock();
    door.throwState();
  } catch (std::string message) {
    std::cout << message;
  }
  return 0;
}
