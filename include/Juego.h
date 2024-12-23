#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <map>

#include "Pelota.h"
#include "Barra.h"
#include "Cancha.h"
#include "Obstaculo.h"
#include "Logica.h"
#include "Niveles.h"
#include "EstadoManager.h"

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
        unsigned int vidas;
        bool finDelJuego;

        void juegoLoop(void);
        void funcionConstructor();
        void funcionPausaRecursi(void);
        void funcionSalirRecursi(void);

        void loadConfig(std::map<std::string, int>& config);
};

#endif // JUEGO_H_INCLUDED
