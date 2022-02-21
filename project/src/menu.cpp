#include "menu.h"

menu::menu(/* args */)
{
    std::cout << "MENU INITIALIZED" << std::endl;
}

menu::~menu()
{
    // std::cout << "MENU DE-INITIALIZED" << std::endl;
}

// This will make a line of '=' at the top and bottom
void menu::mainSeparator(){
    std::cout << std::setw(charWidth) << std::setfill('=') << std::left << "" << std::endl;    
}

// This will make a line of ' - '
void menu::separator(std::string str){

}

void menu::printName(std::string name){
    std::cout << " " "[ " << name << " ]" << std::endl;
}

void menu::dialog(std::string words){
    // TODO:
        // Check if the next word is longer than what we have. 
        // int currentLineCharacterAmount
        // int charSpaceLeft = charWidth-currentLineCharacterAmount-2;
        // str nextWord = str.charsUntillChar(' ');
        // int nextWordLength nextWord.length();
        // 
    std::cout << " ";
    for (size_t i = 0; i < words.length(); i++)
    {
        //TODO:
            // Make a function that checks if the next word fits
            // if it fits, print it out, if not. make a new line.
        if ((i%(charWidth-2)) == 0)
        {
            std::cout << "\n ";
        }
        
        std::cout << words.at(i);
    }
    std::cout << std::endl;    
}

void menu::testSeparator(std::string str){
    std::cout << std::setw(charWidth) << std::setfill('=') << std::left << str << "[ " << "- - - -" << " ]" << std::endl;    
}

void testF(int i)
{
    std::cout << i << " HEY FROM MENU.CPP" << std::endl;
}