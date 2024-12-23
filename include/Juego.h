#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Pelota.h"
#include "Barra.h"
#include "Cancha.h"
#include "Obstaculo.h"
#include "Logica.h"
#include "Niveles.h"

class Juego
{
    public:
        Juego();
        Cancha cancha;
        Pelota pelota;
        Barra barra;
        Obstaculo obstaculos;
        Logica logica;
        Niveles niveles;
        unsigned int puntaje;
        unsigned int record;

        void juegoLoop();
};

#endif // JUEGO_H_INCLUDED
