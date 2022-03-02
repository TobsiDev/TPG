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
    std::cout << std::setw(charWidth) << std::setfill(mainSepChar) << std::left << "" << std::endl;    
}

// This will make a line of ' - '
void menu::separator(std::string str){

}

void menu::printName(std::string name){
    std::cout << " " "[ " << name << " ]" << std::endl;
}

std::string menu::mainSeparatorToString(){
    std::stringstream strStream;
    strStream << std::setw(charWidth) << std::setfill(mainSepChar) << std::left << "" << std::endl;
    return strStream.str();
}

std::string menu::separatorToString(std::string str){
    return "";
}

std::string menu::printNameToString(std::string name){
    std::string str = " [ " + name + " ]" + "\n";
    return str;
} 

void menu::chopString(const std::string &str, std::vector<std::string> &output){
    // Got it from http://www.cplusplus.com/forum/beginner/99171/#msg533234 
    std::string::size_type start = 0; // Where to start
    std::string::size_type last = str.find_first_of(" "); // Finds the first space

    // npos means that the find_first_of wasn't able to find what it was looking for
    // in this case it means it couldn't find another space so we are at the end of the
    // words in the string.
    while (last != std::string::npos)
    {
        // If last is greater then start we have a word ready
        if (last > start)
        {
            output.push_back(str.substr(start, last - start)); // Puts the word into a vector look into how the method substr() works
        }

        start = ++last; // Reset start to the first character of the next word
        last = str.find_first_of(" ", last); // This means find the first space and we start searching at the first character of the next word
    }

    // This will pickup the last word in the file since it won't be added to the vector inside our loop
    output.push_back(str.substr(start));
}

void menu::checkWord(const std::string &str, int currentCharsOnLine){

}

void menu::dialog(std::string string){
    // TODO [X]:
        // Check if the next word is longer than what we have. 
        // int currentLineCharacterAmount
        // int charSpaceLeft = charWidth-currentLineCharacterAmount-2;
        // str nextWord = str.charsUntillChar(' ');
        // int nextWordLength nextWord.length();
        // 

    // TODO [ ]:    
        // MAKE THE TEXT BOLD OR A DIFFERENT COLOR
    
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    std::vector<std::string> words;
    chopString(string, words); // makes a list

    int charLinePoint = 0;
    int charPoint = 0;

    std::cout << " ";
    for (size_t i = 0; i < words.size(); i++)
    {
        
        if (charLinePoint + words[i].length() >= charWidth)
        {
            std::cout << "\n ";
            charLinePoint = 1;
        }

        std::string tempStr = words[i];
        
        for (size_t n = 0; n < words[i].length(); n++)
        {
            char tempChar = tempStr[n];
            std::cout << tempChar;
            std::cout.flush();

            srand((time_t)ts.tv_nsec);
            
            // int randNumb = (rand()%30);
            // usleep(150);

            std::this_thread::sleep_for(std::chrono::milliseconds(20+(rand()%30)) );
            charLinePoint++;;
            charPoint++;
        }
        std::cout << " ";
        charLinePoint++;
        charPoint++;
    }
    std::cout << std::endl;    

    std::cout << std::endl;   
    //words.clear(); 
}

void menu::dialogTwo(std::string name, std::string string){
    
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    std::vector<std::string> words;
    chopString(string, words); // makes a list

    std::string str = "";
    std::string dialogStr = "";
    int charLinePoint = 0;
    // int charPoint = 0;
    // TODO:
        /*
        At every std::cout <<
        Make it strToPrint +=

        I'm gonna print it out every time to make the "UI" slowly expand pr line.
        */
    // string
    std::system("clear");
    dialogStr += mainSeparatorToString();
    dialogStr += printNameToString(name);
    dialogStr += " ";
    for (size_t i = 0; i < words.size(); i++)
    {
        if (charLinePoint + words[i].length() >= charWidth)
        {
            dialogStr += "\n ";
            charLinePoint = 1;
        }

        std::string tempStr = words[i];
        
        for (size_t n = 0; n < words[i].length(); n++)
        {
            /* dialogStr += tempStr[n];
            std::system("clear");
            str = dialogStr + "\n" + mainSeparatorToString();
            std::cout << str;
            std::cout.flush(); */

            // add's the next char to dialogStr and prints the entire string.
            dialogStr += tempStr[n];
            std::system("clear");
            std::cout << dialogStr << "\n" << mainSeparatorToString();
            std::cout.flush();

            srand((time_t)ts.tv_nsec);

            std::this_thread::sleep_for(std::chrono::milliseconds(20+(rand()%30)) ); // Gives it this "typing" feal
            charLinePoint++;;
            // charPoint++;
        }
        dialogStr += " ";
        charLinePoint++;
        // charPoint++;
    }
    std::system("clear");
    std::cout << dialogStr << "\n" << mainSeparatorToString() << std::endl;   

    // std::cout << std::endl;   
}

// This is the "final" dialog function
void menu::dialogFixed(std::string fileName){
    // TODO:
        // Space or some other key makes all of the text show at once. 
        // Or maybe just make it an option. 

    // Used to get a little random time between each letter
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    // Setting some variables. 
    std::string dialogStr = ""; // Stores what's gonna get printed
    int charLinePoint = 0; // Keeps track on how many characters we have left pr line
    int linesLeft = charHeight; // Keeps track on how many lines we have left (24 is the preferred height)

    // Who speaks and what's being said. It's getting it from a file
    std::string name = "", string = "";
    std::ifstream fileStream;
    fileStream.open(dialogLocation+fileName);
    getline(fileStream, name, '|');
    for (size_t i = 0; i <= 1; i++)
    {
        getline(fileStream, string);
    }
    
    // The word list
    std::vector<std::string> words;
    chopString(string, words); // makes a list

    //linesLeft-5; // This doesn't work for some reason?
    //linesLeft--; linesLeft--; linesLeft--; linesLeft--; linesLeft--; // But this does?
    linesLeft = linesLeft-5; 

    std::system("clear");
    dialogStr += mainSeparatorToString();
    dialogStr += printNameToString(name);
    dialogStr += " ";
    charLinePoint++;
    for (size_t i = 0; i < words.size(); i++)
    {
        if (linesLeft >= 1)
        {
            /* code */
            if (charLinePoint + words[i].length() >= charWidth)
            {
                // TODO
                    // Add every line beforehand to an array. 
                    // So we can just call line[2] for the second line
                    // So we just print every line instead of every word
                    /*
                        just make this into a for-loop or an if-statement but throw the words into an array

                        TODO: WRITE PSEUDO CODE
                    */
                    //
                    // Print out the array lines, and make it
                    // scroolable with the arrow keys
                    // 
                
                linesLeft--;
                if (linesLeft >= 1)
                {
                    dialogStr += "\n ";
                    charLinePoint = 1;
                }
            }

            std::string tempStr = words[i];
            if (linesLeft >= 1)
            {
                for (size_t n = 0; n < words[i].length(); n++)
                {
                    // add's the next char to dialogStr and prints the entire string.
                    dialogStr += tempStr[n];
                    std::system("clear");
                    std::cout << dialogStr << "\n";
                    
                    // For debugging. 
                    // Print it bellow the for loop, 
                    // and set the size_t i = amount 
                    // of lines you need for debugging
                    for (size_t i = 0; i < linesLeft; i++)  
                    {
                        std::cout << "\n";
                    }
                    // std::cout << "linesLeft: " << linesLeft << "\n";
                    std::cout << mainSeparatorToString();
                    std::cout.flush();

                    srand((time_t)ts.tv_nsec);

                    // TODO: MAKE AN ENUM SWITCH CASE TO DETERMEN IF WE'RE USING THE FAST, NORMAL OR SLOW SPEED
                    // 20 - 25 is fast
                    // 50 is normal
                    // 75 is slow
                    std::this_thread::sleep_for(std::chrono::milliseconds(/*20+(rand()%30)*/0)); // Gives it this "typing" feal
                    charLinePoint++;;
                }
                dialogStr += " ";
                charLinePoint++;
            }
            
        }
        else
        {
            dialogStr += "\n ...";
            break;
        }
    }
    
    // If there is space left, this for loop filles the rest of the console with '\n'
    for (size_t i = 0; i < linesLeft; i++)
    {
        dialogStr += "\n";
    }
    
    std::system("clear");
    std::cout << dialogStr << "\n" << mainSeparatorToString();
    std::cout.flush();

    //              DEBUGGING               //
    // std::cout << "Name: " << name << std::endl;
    // std::cout << "String: " << string << std::endl;
    //              DEBUGGING               //
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));

}

// This is for testing
// I'm trying to make a vector store all the text a requested dialog have
// and "pre-make" the lines in the vector 
void menu::dialogFixedTwo(std::string fileName, std::vector<std::string> strVec){
    // Who speaks and what's being said. It's getting it from a file
    std::string name = "", string = "";
    std::ifstream fileStream;
    fileStream.open(dialogLocation+fileName);
    getline(fileStream, name, '|');
    for (size_t i = 0; i <= 1; i++)
    {
        getline(fileStream, string);
    }

    // The word list
    std::vector<std::string> words;
    chopString(string, words); // makes a list

    std::vector<std::string> lines;

    // TEST STUFF
    lines.push_back(mainSeparatorToString());
    lines.push_back(printNameToString(name));
    // TEST STUFF
    
    int linePoint = 1;
    int line = 0;
    std::string str = " ";


    for (size_t i = 0; i < words.size(); i++)
    {
        if (linePoint + words[i].length() < charWidth)
        {
            str += words[i];
            // std::cout << "BEFORE" << str << std::endl;
            linePoint += words[i].length();
            str += " ";
            // std::cout << "AFTER" << str << std::endl;
            linePoint = linePoint+1;
        }
        else
        {
            // std::cout << "PUSH BACK" << std::endl;
            lines.push_back(str);
            str = " ";
            // std::cout << str << std::endl;
            linePoint = 1;
        }
        
        
        // lines.push_back();
        // std::cout << words[i] << std::endl;
    }

    lines.push_back(str);
    lines.push_back(mainSeparatorToString());
    

    for (size_t n = 0; n < lines.size(); n++)
    {
        std::cout << lines[n] << std::endl;
    }

    std::cout << lines.size() << std::endl;
    
    testFunc();
    // std::cout << string << std::endl;

}

void menu::testSeparator(std::string str){
    std::cout << std::setw(charWidth) << std::setfill('=') << std::left << str << "[ " << "- - - -" << " ]" << std::endl;    
}

void testF(int i)
{
    std::cout << i << " HEY FROM MENU.CPP" << std::endl;
}