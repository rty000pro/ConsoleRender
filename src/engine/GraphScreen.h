#pragma once
#include "Screen.h"
#include <vector>
#include <string>
#include <cmath>
#include <functional>

class graph : public screen
{
public:
    graph(int rows,int cols) : screen(rows,cols) {};

    std::string& operator()(double x, double y)
    {
        int r = (int)std::lround(screen::getRows() / 2.0 - y);
        int c = (int)std::lround(screen::getCols() / 2.0 + x);

        return screen::operator()(r,c);
    }

    int getMaxX() const { return (int)std::lround(screen::getRows() / 2.0); }
    int getMaxY() const { return (int)std::lround(screen::getCols() / 2.0); }
    
    void DrawGraph(graph& main);
    void DrawFunction(graph& main,std::function<double(double)> f, const std::string& sym = "#");

    void DrawDemo(graph& main);
};