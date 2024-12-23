#ifndef PELOTA_H
#define PELOTA_H

#include "Dupla.h"

class Pelota
{
    public:
        Pelota();
        Dupla<int> direccion; // Duple template class for direction (dirX, dirY)
        Dupla<unsigned int> posicion; // Duple template class for position (posX, posY)

        void mover(void);
        void reiniciar(void);
        void rebotarY(void);
        void rebotarX(void);

        void dibujar(void);
};

#endif // PELOTA_H
