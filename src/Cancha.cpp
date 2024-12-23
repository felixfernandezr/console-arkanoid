#include "Cancha.h"
#include <iostream>

Cancha::Cancha()
{
    this->alto = 24;
    this->ancho = 59;
}

void Cancha::delinear()
{
    for(int i = 0; i < ancho + 2; i++)
        std::cout << '#';
    std::cout << std::endl;

    for(int i = 0; i < alto; i++)
    {
        std::cout << '#';
        for(int j = 0; j < ancho; j++)
        {
            std::cout << ' ';
        }
        std::cout << '#' << std::endl;
    }

    for(int i = 0; i < ancho + 2; i++)
        std::cout << '#';
}
