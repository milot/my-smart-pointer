#include <iostream>
#include "Test.h"

Test::Test()
{

}

Test::Test(const std::string &message)
    : m_Message(message)
{

}

void Test::printMessage() {
    std::cout << m_Message << std::endl << std::flush;
}

std::string Test::message() const {
    return m_Message;
}
