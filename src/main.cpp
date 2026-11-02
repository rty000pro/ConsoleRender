#include "engine/Screen.h"
#include "engine/GraphScreen.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[])
{
    graph test(34,34);
    test.DrawFunction(test, [](double x) { return 2 * std::sin(x);});
    return 0;
}