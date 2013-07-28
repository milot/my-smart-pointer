#include <iostream>
#include <string>
#include "SmartPointer.cpp"
#include "Test.h"

int main()
{
    std::string message = "I smell bones in the pylons, blood beneath the stone blocks. Men died building this structure.";
    std::string message2 = "The air is heavy and stale. Some acrid powders still linger in it.";

    // Test the smart pointer.
    SmartPointer<Test> testObject(new Test(message));
    testObject->printMessage();

    // Test the ownership transfer
    Test* t = testObject.take();
    t->printMessage();

    SmartPointer<Test> anotherTestObject;
    anotherTestObject.addPointer(new Test(message2));
    anotherTestObject->printMessage();

    // It should throw the IllegalPointerSetException after uncommenting these two lines.
    //anotherTestObject.addPointer(new Test("bb"));
    //anotherTestObject->printMessage();

    return 0;
}

