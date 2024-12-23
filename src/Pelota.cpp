#include "Pelota.h"
#include <iostream>
#include <windows.h>

Pelota::Pelota()
{
    this->posicion = Dupla<unsigned int>(30, 15);
    this->direccion = Dupla<int>(1, 1);
}

void Pelota::mover(void)
{
    this->posicion[0] += this->direccion[0];
    this->posicion[1] += this->direccion[1];
}

void Pelota::reiniciar(void)
{
    this->posicion = Dupla<unsigned int>(30, 15);
    this->direccion = Dupla<int>(1, 1);
}

void Pelota::rebotarY(void)
{
    this->direccion[1] = -this->direccion[1];
}

void Pelota::rebotarX(void)
{
    this->direccion[0] = -this->direccion[0];
}
void Pelota::dibujar(void)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = this->posicion[0];
    dwPos.Y= this->posicion[1];
    SetConsoleCursorPosition(hcon,dwPos);
    std::cout << 'O';
}
