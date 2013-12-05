#include <iostream>
#include <string>
#include "SmartPointer.cpp"
#include "SmartSharedPointer.cpp"
#include "Test.h"

int main(){
  std::string message = "I smell bones in the pylons, blood beneath the stone blocks. Men died building this structure.";
  std::string message2 = "The air is heavy and stale. Some acrid powders still linger in it.";
  std::string message3 = "Ego homini Lupus";

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

  SmartSharedPointer<Test> testSharedPtr(new Test(message3));
  testSharedPtr->printMessage();

  // Anonymous braces to test the scope of shared pointer
  {
    SmartSharedPointer<Test> testSharedPtr2 = testSharedPtr;
    testSharedPtr2->printMessage();
    // Destructor of testSharedPtr2 but Test object won't be deleted

    SmartSharedPointer<Test> testSharedPtr3;
    testSharedPtr3 = testSharedPtr;
    // Destructor of testSharedPtr3 but Test object won't be deleted
  }
  // Destruction of testSharedPtr and Test object will be deleted.


  return 0;
}

