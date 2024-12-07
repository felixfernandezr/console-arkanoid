#ifndef BARRA_H
#define BARRA_H


class Barra
{
    public:
        Barra(unsigned int posX);
        unsigned int posX;
        unsigned int posY;
        unsigned int largo;

        void mover(int direccion);
        void moverIzquierda(void);
        void moverDerecha(void);
        void dibujar(void);
        void hitTecla(char);
};

#endif // BARRA_H
