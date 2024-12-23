#ifndef BARRA_H
#define BARRA_H

#include "Dupla.h"

class Barra
{
    public:
        Barra(unsigned int posX);
        Dupla<unsigned int> posicion; // Duple template class for position (posX, posY)
        unsigned int largo;
        unsigned int posInit;

        void mover(int direccion);
        void moverIzquierda(void);
        void moverDerecha(void);
        void dibujar(void);
        void hitTecla(char);
        void reiniciar(void);
};

#endif // BARRA_H
