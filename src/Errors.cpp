#include <iostream>

void displayMyError(bool question, char const *msg)
{
    if (question)
    {
        std::cout << msg;
        exit(1);
    }
}