#include "Barra.h"
#include <iostream>
#include <windows.h>

// Constructor initializes bar X,Y position and width
Barra::Barra(unsigned int posX)
{
    this->posicion = Dupla<unsigned int>(posX, 24);
    this->largo = 8;
    this->posInit = this->posicion;
}

// Bar movement
void Barra::mover(int direccion)
{
    if(((direccion == -1) && (this->posicion[0] > 1)) || ((direccion==1) && (this->posicion[0] < 60 - this->largo)))
    {
        this->posicion[0] += direccion; // Change bar X axis position
    }
}
// Move to left (-1)
void Barra::moverIzquierda(void)
{
    this->mover(-1);
    this->mover(-1);
}
// Move to right (+1)
void Barra::moverDerecha(void)
{
    this->mover(+1);
    this->mover(+1);
}
// Move to right or left depending on key stroke
void Barra::hitTecla(char tecla)
{
    if(tecla == 'a')
        this->moverIzquierda();
    else if(tecla == 'd')
        this->moverDerecha();
}
// Bar rendering
void Barra::dibujar(void)
{
    for(unsigned int i=0; i< this->largo; i++)
    {
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = this->posicion[0] + i;
        dwPos.Y= this->posicion[1];
        SetConsoleCursorPosition(hcon,dwPos);
        std::cout << '#';
    }
}

void Barra::reiniciar()
{
    this->posicion = this->posInit;
}
