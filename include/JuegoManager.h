#ifndef JUEGOMANAGER_H_INCLUDED
#define JUEGOMANAGER_H_INCLUDED

#include "EstadoJuego.h"
#include "Juego.h"

class JuegoManager {
    public:
        JuegoManager();
        void jugar();
        void mostrarMenuInicio(void);
        void mostrarPantallaFin(void);
        void cambiarEstado(EstadoJuego nuevoEstado);
        void inicializarNivel(void);

    private:
        Juego juego;
        EstadoJuego estadoActual;
        Niveles niveles;
        unsigned int nivelActual;
        bool gameOver;
};

#endif // JUEGOMANAGER_H_INCLUDED
