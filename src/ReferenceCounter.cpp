#include "ReferenceCounter.h"

ReferenceCounter::ReferenceCounter()
    : counter(0) {

}

void ReferenceCounter::addReference() {
  ++counter;
}

int ReferenceCounter::releaseReference() {
  return --counter;
}
