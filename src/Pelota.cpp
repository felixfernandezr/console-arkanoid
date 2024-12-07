#include "Pelota.h"
#include <iostream>
#include <windows.h>

Pelota::Pelota()
{
    this->posX = 30;
    this->posY = 15;
    this->dirX = 1;
    this->dirY = 1;
}

void Pelota::mover(void)
{
    this->posX += this->dirX;
    this->posY += this->dirY;
}

void Pelota::reiniciar(void)
{
    this->posX = 30;
    this->posY = 15;
    this->dirX = 1;
    this->dirY = 1;
}

void Pelota::rebotarY(void)
{
    this->dirY = -this->dirY;
}

void Pelota::rebotarX(void)
{
    this->dirX = -this->dirX;
}
void Pelota::dibujar(void)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = this->posX;
    dwPos.Y= this->posY;
    SetConsoleCursorPosition(hcon,dwPos);
    std::cout << 'O';
}
