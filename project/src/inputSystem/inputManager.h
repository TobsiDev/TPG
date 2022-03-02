#pragma once

#include <iostream>

// TODO:
    // Make this a "writeable" input. Like in the old adventure games.
    // Look NORTH
    // or
    // buy "Sword of the damned"

    /*
    
    Stats -> Inventory -> Items
    Stats scans the players inventory, the inventory give the intems the user have (Could store it in an array Inventory["Tobsi's Sword", "Eggs", "Plastic bag"])
    and an item file would use specific characters to know whats's what

    Tobsi's Sword|          // Name of the item
    Description goes here#  // Description
    20¤                     // HP
    10½                     // Mana
    5%                      // Strength
    7¥                      // Agility
    58\                     // Intelect
    2¡                      // Something else
    7£                      // Value


    I could also just remember what line is what, so I don't have to use the specific characters

    Tobsi's Sword           // Name of the item
    Description goes here   // Description
    20                      // HP
    10                      // Mana
    5                       // Strength
    7                       // Agility
    58                      // Intelect
    2                       // Something else
    7                       // Value

    true                    // Equipable
    false                   // Usable
    false                   // Consumable

    Could also just have a "base class" and use inharetence to make new items

    itemName = "Tobsi's Sword";
    itemDesc = "Description goes here";
    itemHP = 20;
    itemMana = 10;
    itemStrength = 5;
    itemAgility = 7;
    itemIntelect = 58;

    itemValue = 7;

    isEquipable = true;
    isUsable = false;
    isConsumable = false;

    */
class inputManager 
{
private:
public:
    inputManager(/* args */);
    ~inputManager();
};

void testFunc();