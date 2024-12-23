#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

#include <vector>

class Obstaculo
{
    public:
        Obstaculo(unsigned int filas, unsigned int columnas, unsigned int ancho);

    private:
        unsigned int filas;
        unsigned int columnas;
        unsigned int ancho;

        std::vector<std::vector<int>> grilla;

        void inicializarObstaculos(void);

    public:
        bool checkColision(int pelotaX, int pelotaY);
        void dibujar(void);

};

#endif // OBSTACULO_H_INCLUDED
