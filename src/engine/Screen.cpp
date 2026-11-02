#include "Screen.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

void screen::PrintScreen(screen& main,PRINTTYPE t)
{
    int terminal_cols = cols * 2 + 4;
    int terminal_rows = rows + 2;
    std::cout << "\033[8;" << terminal_rows << ";" << terminal_cols << "t";
    std::cout << std::flush;
    switch (t)
    {
    case PRINTTYPE::classic:
    {
        for (int i = 0; i < main.getRows(); ++i) 
        {
            for (int j = 0; j < main.getCols(); ++j) 
            {
                std::cout << main(i, j) << main(i,j);
            }
            std::cout << "\n";
        }
        break;
    }
    case PRINTTYPE::graph:
    {
        for (int i = 0; i < main.getRows(); ++i) 
        {
            for (int j = 0; j < main.getCols(); ++j) 
            {
                std::cout << " " << main(i, j);
            }
            std::cout << "\n";
        }
        break;
    }
    default:
    {
        for (int i = 0; i < main.getRows(); ++i) 
        {
            for (int j = 0; j < main.getCols(); ++j) 
            {
                std::cout << "$";
            }
            std::cout << "\n";
        }
        break;
    }
    }
    
    
}

void screen::ScreenDemo(DEMOTYPE t)
{
    bool color = false;
    std::string char_str = "#";
    switch (t)
    {
    case DEMOTYPE::classic:
        color = false;
        char_str = "#";
        break;
    case DEMOTYPE::classicColor:
        color = true;
        char_str = "#";
        break;
    case DEMOTYPE::nocolor:
        color = false;
        char_str = "█";
        break;
    case DEMOTYPE::color:
        color = true;
        char_str = "█";
        break;  
    default:
        std::cout << "Error! No type this DEMO!" << std::endl;
        std::abort();
        break;
    }
    
    screen Demo(screen::getRows(), screen::getCols());
    double cx = Demo.getCols() / 2.0;
    double cy = Demo.getRows() / 2.0;
    double max_radius = std::min(cx, cy) - 1.0;
    int num_rays = 5;

    for (int i = 0; i < Demo.getRows(); ++i)
    {
        Demo(i, 0) = "█";
        Demo(i, Demo.getCols() - 1) = "█";
    }
    for (int i = 0; i < Demo.getCols(); ++i)
    {
        Demo(0, i) = "█";
        Demo(Demo.getRows() - 1, i) = "█";
    }

    double m  = num_rays;
    double pi = std::acos(-1.0);

    const std::string colors[5] = {
        "\033[31m", // красный
        "\033[32m", // зелёный
        "\033[33m", // жёлтый
        "\033[34m", // синий
        "\033[37m"  // белый
    };
    const std::string RESET = "\033[0m";
    const std::string BLOCK = char_str;

    for (int y = 0; y < Demo.getRows(); ++y) {// Формулу спиздил у нейронки + попросил подкрутить цвета к 'Лепесткам'
        for (int x = 0; x < Demo.getCols(); ++x) {

            double dx = x - cx;
            double dy = cy - y;

            double r = std::sqrt(dx * dx + dy * dy);
            if (r < 0.5) continue;

            double theta = std::atan2(dy, dx);
            double n     = std::floor((m * theta + pi) / (2.0 * pi));
            double phi   = theta - (2.0 * pi / m) * n;

            double r_star       = max_radius * (std::cos(pi / m) / std::cos(phi));
            double star_final_r = r_star * (0.6 + 0.4 * std::cos(m * phi));

            if (r <= star_final_r) {
                if (color) {
                    int petal = ((int)n % 5 + 5) % 5;
                    Demo(y, x) = colors[petal] + BLOCK + RESET;
                } else {
                    Demo(y, x) = BLOCK;
                }
            }
        }
    }

    PrintScreen(Demo,PRINTTYPE::classic);
}