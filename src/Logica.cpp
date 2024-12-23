#include "Logica.h"
#include <iostream>

#include "Utils.h"

Logica::Logica() {}

bool Logica::juegoUpdate(Pelota* pelota, Barra* barra, Obstaculo* obstaculos, unsigned int* puntaje, unsigned int* record, unsigned int* vidas)
{
    // Checking for obstacle collision
    if(obstaculos->checkColision(pelota->posicion[0], pelota->posicion[1])) // Sending ball x,y using a duple Dupla (check Pelota.h)
    {
        pelota->rebotarY(); // If collision is true change direction in Y axis (*-1)
        *puntaje += 10; // Add to score
        if(*puntaje > *record) // Check if record
            {
                *record = *puntaje;
            }
    }

    // Colission Logic
    // Walls
    if(pelota->posicion[1]==0) // If ball Y position is 0 (actual console screen boundary)
    {
        pelota->rebotarY(); // Change ball Y direction (*-1)
    }
    if(pelota->posicion[0]==0 || pelota->posicion[0]==59) // if ball X position is 0 or 59
    {
        pelota->rebotarX(); // Change ball X direction (*-1)
    }

    // Bar
    if(pelota->posicion[1]==barra->posicion[1]) // If ball Y position == bar Y position
    {
        // And if ball position is in between bar start and end position (bar X position + bar length)
        if( (pelota->posicion[0] >= barra->posicion[0]) && (pelota->posicion[0] < barra->posicion[0] + barra->largo) )
        {
            pelota->rebotarY(); // Change ball Y direction
        }
    }

    // If ball does not hit bar
    if(pelota->posicion[1]==27)
    {
        *vidas = *vidas - 1;
        *puntaje = 0;
        if(*vidas > 0)
            Utils::cuentaRegresivaRecursi(3);
        pelota->reiniciar();
    }

    // If ball Y position is more than bar Y position (24) or Level is Completed. End loop
    if((*vidas < 1) || (obstaculos->checkNivelCompleto()))
    {
        return true; // Ending function with true
    }

    return false;
}
