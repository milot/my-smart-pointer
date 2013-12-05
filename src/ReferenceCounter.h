#pragma once

class ReferenceCounter {
public:
  ReferenceCounter();
  void addReference();
  int releaseReference();

private:
  int counter;
};
