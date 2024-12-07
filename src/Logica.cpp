#include "Logica.h"
#include <iostream>
#include <windows.h>

Logica::Logica() {}

void Logica::juegoUpdate(Pelota* pelota, Barra* barra, Obstaculo* obstaculos, unsigned int* puntaje, unsigned int* record)
{
    // Checking for obstacle collision
    if(obstaculos->checkColision(pelota->posX, pelota->posY))
    {
        pelota->rebotarY();
        *puntaje += 10;
        if(*puntaje > *record)
            {
                *record = *puntaje;
            }
    }


    // Colission Logic
    // Walls
    if(pelota->posY==0)
    {
        pelota->rebotarY();
    }
    if(pelota->posX==0 || pelota->posX==59)
    {
        pelota->rebotarX();
    }

    // Bar
    if(pelota->posY==barra->posY)
    {
        if(pelota->posX >= barra->posX && pelota->posX < barra->posX + barra->largo)
        {
            pelota->rebotarY();
        }
    }

    // Game Over
    if(pelota->posY==27)
    {
        pelota->reiniciar();
        *puntaje = 0;
    }
}
