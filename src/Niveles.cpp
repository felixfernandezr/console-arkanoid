#include "Niveles.h"
#include <iostream>

Niveles::Niveles() {}

std::vector<std::vector<unsigned int>> Niveles::nivel1()
{
    this->plantilla.resize(2, std::vector<unsigned int>(15));

    this->plantilla = {
        {0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1}
    };

    return this->plantilla;
}

std::vector<std::vector<unsigned int>> Niveles::nivel2()
{
    this->plantilla.resize(3, std::vector<unsigned int>(15));

    this->plantilla = {
        {0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1}
    };

    return this->plantilla;
}

std::vector<std::vector<unsigned int>> Niveles::nivel3()
{
    this->plantilla.resize(4, std::vector<unsigned int>(15));

    this->plantilla = {
        {0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    return this->plantilla;
}
