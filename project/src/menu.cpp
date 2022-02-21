#include "menu.h"

menu::menu(/* args */)
{
    std::cout << "MENU INITIALIZED" << std::endl;
}

menu::~menu()
{
    std::cout << "MENU DE-INITIALIZED" << std::endl;
}

void testF(int i)
{
    std::cout << i << " HEY FROM MENU.CPP" << std::endl;
}