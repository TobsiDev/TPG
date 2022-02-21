#pragma once
#include <iostream>
#include <iomanip> // std::setfill, std::setw
#include <string>

class menu
{
private:
    int charWidth = 64;
    /* data */
public:
    menu(/* args */);
    ~menu();

    void mainSeparator(); // This will make a line of '=' at the top and bottom
    void separator(std::string str); // This will make a line of ' - '
    void printName(std::string name); 

    void dialog(std::string words);
    
    void testSeparator(std::string str); // This will make a line of '=' at the top and bottom

};

void testF(int i);