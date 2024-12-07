#include "Inputs.h"
#include <iostream>
#include <conio.h>

Inputs::Inputs(){}

char Inputs::getCharacs()
{
    char pressedKey;
    if(_kbhit())
        pressedKey = _getch();

    return pressedKey;
}
