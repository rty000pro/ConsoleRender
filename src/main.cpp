#include "engine/Screen.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[])
{
    int rows = 35;
    int cols = 35;
    DEMOTYPE type = DEMOTYPE::classicColor;

    // argv[1] = размер (rows), argv[2] = размер (cols), argv[3] = тип
    // Всё опционально — что не передали, берётся по умолчанию
    if (argc > 1) rows = std::atoi(argv[1]);
    if (argc > 2) cols = std::atoi(argv[2]);

    if (argc > 3) {
        std::string t = argv[3];
        if      (t == "classic")      type = DEMOTYPE::classic;
        else if (t == "classicColor") type = DEMOTYPE::classicColor;
        else if (t == "nocolor")      type = DEMOTYPE::nocolor;
        else if (t == "color")        type = DEMOTYPE::color;
        else {
            std::cerr << "Unknown type: " << t << "\n";
            std::cerr << "Use: classic | classicColor | nocolor | color\n";
            return 1;
        }
    }
    if (rows < 5 || cols < 5) {
        std::cerr << "Size too small (min 5x5)\n";
        return 1;
    }

    screen monitor(rows, cols);
    monitor.ScreenDemo(type);
    return 0;
}