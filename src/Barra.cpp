#include "Barra.h"
#include <iostream>
#include <windows.h>

Barra::Barra(unsigned int posX)
{
    this->posX = posX;
    this->posY = 24;
    this->largo = 8;
}

void Barra::mover(int direccion)
{
    if(direccion==-1 && this->posX >1 || direccion==1 && this->posX < 60 - this->largo)
    {
        this->posX += direccion;
    }
}
void Barra::moverIzquierda(void)
{
    this->mover(-1);
    this->mover(-1);
}

void Barra::moverDerecha(void)
{
    this->mover(+1);
    this->mover(+1);
}

void Barra::hitTecla(char tecla)
{
    if(tecla == 'a')
        this->moverIzquierda();
    else if(tecla == 'd')
        this->moverDerecha();
}

void Barra::dibujar(void)
{
    for(unsigned int i=0; i< this->largo; i++)
    {
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = this->posX + i;
        dwPos.Y= this->posY;
        SetConsoleCursorPosition(hcon,dwPos);
        std::cout << '#';
    }
}
