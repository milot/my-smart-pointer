#include <iostream>
#include "SmartDeleter.cpp"
#include "Test.h"

int main()
{
    // Test the smart pointer.
    SmartDeleter<Test> testObject(new Test("My message"));
    testObject->printMessage();

    // Test the ownership transfer
    Test* t = testObject.take();
    t->printMessage();

    return 0;
}

