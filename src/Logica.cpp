#include "Logica.h"
#include <iostream>
#include <windows.h>

Logica::Logica() {}

bool Logica::juegoUpdate(Pelota* pelota, Barra* barra, Obstaculo* obstaculos, unsigned int* puntaje, unsigned int* record)
{
    // Checking for obstacle collision
    if(obstaculos->checkColision(pelota->posicion[0], pelota->posicion[1]))
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
    if(pelota->posicion[1]==0)
    {
        pelota->rebotarY();
    }
    if(pelota->posicion[0]==0 || pelota->posicion[0]==59)
    {
        pelota->rebotarX();
    }

    // Bar
    if(pelota->posicion[1]==barra->posicion[1])
    {
        if(pelota->posicion[0] >= barra->posicion[0] && pelota->posicion[0] < barra->posicion[0] + barra->largo)
        {
            pelota->rebotarY();
        }
    }

    // Game Over
    if(pelota->posicion[1]==27)
    {
        pelota->reiniciar();
        *puntaje = 0;
        return true; // Game over signal
    }

    return false;
}
