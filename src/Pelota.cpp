#include "Pelota.h"
#include <iostream>
#include <windows.h>

// Ball class with fundamental logic
Pelota::Pelota()
{
    this->posicion = Dupla<unsigned int>(30, 15); // Ball starting position
    this->direccion = Dupla<int>(1, 1); // Starting direction (+1 axis X and +1 axis Y)
}

// Moving ball
void Pelota::mover(void)
{
    this->posicion[0] += this->direccion[0]; // X position + X direction (direction is +1 or -1 for each axis)
    this->posicion[1] += this->direccion[1]; // Moving in Y axis
}

// Reset ball position and direction
void Pelota::reiniciar(void)
{
    this->posicion = Dupla<unsigned int>(30, 15);
    this->direccion = Dupla<int>(1, 1);
}

// Bounce Y
void Pelota::rebotarY(void)
{
    this->direccion[1] = -this->direccion[1]; // Inverts direction current value (if it was +1 it changes to -1)
}
//Bounce X
void Pelota::rebotarX(void)
{
    this->direccion[0] = -this->direccion[0]; // Inverts X axis direction
}
// Ball rendering
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
