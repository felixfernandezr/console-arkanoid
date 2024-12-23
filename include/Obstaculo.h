#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

#include <vector>
#include "Niveles.h"

class Obstaculo
{
    public:
        Obstaculo(unsigned int ancho);

    private:
        unsigned int filas;
        unsigned int columnas;
        unsigned int ancho;
        std::vector<std::vector<unsigned int>> grilla;

    public:
        bool checkColision(unsigned int pelotaX, unsigned int pelotaY);
        void dibujar(void);
        bool checkNivelCompleto(void);
        void inicializarObstaculos(std::vector<std::vector<unsigned int>> nivel);

};

#endif // OBSTACULO_H_INCLUDED
