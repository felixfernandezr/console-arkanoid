#ifndef LOGICA_H_INCLUDED
#define LOGICA_H_INCLUDED
#include "Pelota.h"
#include "Barra.h"
#include "Obstaculo.h"

class Logica
{
    public:
        Logica();
        unsigned int* puntaje;
        unsigned int* record;

        bool juegoUpdate(Pelota* pelota, Barra* barra, Obstaculo* obstaculos, unsigned int* puntaje, unsigned int* record);
};

#endif // LOGICA_H_INCLUDED
