#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>

enum class DEMOTYPE
{
    classic,
    classicColor,
    nocolor,
    color
};

enum class PRINTTYPE
{
    classic,
    graph
};

class screen {
private:
    std::vector<std::string> data; // Теперь здесь хранятся символы char
    int rows;
    int cols;

public:
    screen(int r, int c)noexcept : rows(r), cols(c), data(r * c," ") {std::cout << "init <" << screen::getRows() << "x" << screen::getCols() << ">" << std::endl;}
    //screen(int&& r, int&& c) : rows(std::move(r)), cols(std::move(c)), data(std::move(r) * std::move(c)," ") {}
    
    std::string& operator()(int r, int c) 
    {
        return data[r * cols + c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    
    void PrintScreen(screen& main,PRINTTYPE t);

    void ScreenDemo(DEMOTYPE t);
};
