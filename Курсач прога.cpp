
#include <iostream>
#include "Arena.h"
#include "Predator.h"
#include "Prey.h"
#include "Console_utils.h"


int main()
{
    Arena a;
    Prey prey(false);
    Predator pred(true);


    a.Draw();
    setCursorPosition(0, 0);
    a.Update(pred, prey);
    a.Draw();

    //setCursorPosition(10, 5);
    //std::cout << "CHEESE";
    //setCursorPosition(10, 5);
    //std::cout << 'W';
    //setCursorPosition(10, 9);
    //std::cout << 'Z';
    //setCursorPosition(10, 5);
    //std::cout << "     ";  // Overwrite characters with spaces to "erase" them
    //std::cout.flush();
    //const unsigned short DARK_BLUE = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
    //const unsigned short BRIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    //setConsoleColour(DARK_BLUE);
    //std::cout << "Hello ";
    //setConsoleColour(BRIGHT_BLUE);
    //std::cout << "world";

    //std::cout << "!" << std::endl;

    
}
