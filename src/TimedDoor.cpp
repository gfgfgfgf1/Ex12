// Copyright 2021 DB

#include "TimedDoor.h"

#include <time.h>
#include <string>

bool TimedDoor::isDoorOpened() { return opened; }

TimedDoor::TimedDoor(int t)
    : iTimeout(t), opened(false), adapter(new DoorTimerAdapter(*this)) {}

void TimedDoor::unlock() {
  opened = false;
  adapter->Timeout();
}

void TimedDoor::lock() { opened = false; }

void TimedDoor::DoorTimeOut() const { throw std::string("close this door!"); }

void TimedDoor::throwState() {
  if (opened) {
    std::string str1 = "the door is opened!";
    throw(str1);
  } else {
    std::string str2 = "close this door!";
    throw(str2);
  }
}

int TimedDoor::getTime() const { return this->iTimeout; }

void DoorTimerAdapter::Timeout() {
  Timer t;
  t.tregister(door.getTime(), this);
  door.DoorTimeOut();
}

DoorTimerAdapter::DoorTimerAdapter(const TimedDoor& _door) : door(_door) {}

void Timer::sleep(int _t) {
  time_t start = clock();
  while (clock() < start + _t * CLOCKS_PER_SEC) {
  }
}

void Timer::tregister(int time, TimerClient* timer) { sleep(time); }
