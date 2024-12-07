#ifndef PELOTA_H
#define PELOTA_H

class Pelota
{
    public:
        Pelota();
        int dirX;
        int dirY;
        unsigned int posX;
        unsigned int posY;

        void mover(void);
        void reiniciar(void);
        void rebotarY(void);
        void rebotarX(void);

        void dibujar(void);
};

#endif // PELOTA_H
