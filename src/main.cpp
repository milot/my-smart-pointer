#include <iostream>
#include "SmartDeleter.cpp"
#include "Test.h"

int main()
{
    SmartDeleter<Test> testObject(new Test("My message"));
    testObject->printMessage();

    return 0;
}

