#ifndef JUEGO_H
#define JUEGO_H

#include "Pelota.h"
#include "Barra.h"
#include "Cancha.h"
#include "Obstaculo.h"
#include "Logica.h"

class Juego
{
    public:
        Juego();
        Cancha cancha;
        Pelota pelota;
        Barra barra;
        Obstaculo obstaculos;
        Logica logica;
        unsigned int puntaje;
        unsigned int record;

        void jugar(void);
};

#endif // JUEGO_H
