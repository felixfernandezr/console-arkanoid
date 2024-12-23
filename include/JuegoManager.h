#ifndef JUEGOMANAGER_H_INCLUDED
#define JUEGOMANAGER_H_INCLUDED

#include "EstadoJuego.h"
#include "Juego.h"

class JuegoManager {
    public:
        JuegoManager();
        void jugar();
        void mostrarMenuInicio();
        void mostrarPantallaFin();
        void cambiarEstado(EstadoJuego nuevoEstado);

    private:
        Juego juego;
        EstadoJuego estadoActual;
        bool gameOver;
};

#endif // JUEGOMANAGER_H_INCLUDED
