#pragma once

#include <iostream>
#include <iomanip> // std::setfill, std::setw
#include <vector>
#include <string>

#include <sstream>
#include <fstream>
#include <filesystem>

#include <stdlib.h>

#include <time.h>

#include "inputManager.h"

// #include <unistd.h>
#include <chrono>
#include <thread>

class menu
{
private:
    // This is my consoles standart width and height
    short int charWidth = 80;
    short int charHeight = 24;

    std::string dialogLocation = "./dialogs/"; // Maybe do something like ./dialogs/person/lines.dia

    char mainSepChar = '=';
    /* data */
public:
    menu(/* args */);
    ~menu();

    void mainSeparator(); // This will make a line of '=' at the top and bottom
    void separator(std::string str); // This will make a line of ' - '
    void printName(std::string name); 

    std::string mainSeparatorToString(); // This will make a line of '=' at the top and bottom
    std::string separatorToString(std::string str); // This will make a line of ' - '
    std::string printNameToString(std::string name); 

    void chopString(const std::string &str, std::vector<std::string> &output);
    void checkWord(const std::string &str, int currentCharsOnLine);
    void dialog(std::string words);
    void dialogTwo(std::string name, std::string string);
    void dialogFixed(std::string fileName/*, std::string string*/);
    void dialogFixedTwo(std::string fileName, std::vector<std::string> strVec/*, std::string string*/);
    
    void testSeparator(std::string str); // This will make a line of '=' at the top and bottom

};

void testF(int i);