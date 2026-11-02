#include "GraphScreen.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include <thread>

void graph::DrawGraph(graph& main)
{
    //Невидимая рамка что бы нормально отображалось
    for (int i = 0; i < main.getRows(); i++)
    {
        main.screen::operator()(i, 0) = " ";
        main.screen::operator()(i, main.getCols() - 1) = " ";
    }
    for (int i = 0; i < main.getCols(); i++)
    {
        main.screen::operator()(0, i) = " ";
        main.screen::operator()(main.getRows() - 1, i) = " ";
    }
    //График
    for(int i = -main.getMaxX();i < main.getMaxX();i++)
    {
        if(i % 5 != 0)
        {
            main(i,0) = "-";
        }
        else
        {
            main(i,0) = "◉";
        }
    }
    for(int i = -main.getMaxY();i < main.getMaxY();i++)
    {
        if(i % 5 != 0)
        {
            main(0,i) = "|";
        }
        else
        {
            main(0,i) = "◉";
        }
    }
    main(0, 0) = "0";
    // Выводим
    screen::PrintScreen(main,PRINTTYPE::graph);
}
void graph::DrawFunction(graph& main,std::function<double(double)> f, const std::string& sym)
{
    DrawGraph(main);

    for (int sy = 0; sy < main.getRows(); ++sy) {
    for (int sx = 0; sx < main.getCols(); ++sx) {
        double x = sx - main.getCols() / 2.0;
        double y = main.getRows() / 2.0 - sy;
        double fy = f(x);
        
        if (std::isfinite(fy) && std::abs(fy - y) < 0.5) {
            std::cout << "\033[2J\033[H";

            if (std::abs(x) < 0.5 && std::abs(y) < 0.5) {
                continue; 
            }

            main(x, y) = sym;
            screen::PrintScreen(main,PRINTTYPE::graph); 

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}
}