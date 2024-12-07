#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

class Obstaculo
{
    public:
        Obstaculo(unsigned int filas, unsigned int columnas, unsigned int ancho);

    private:
        static const int MAX_FILA = 10;
        static const int MAX_COL = 15;
        unsigned int filas;
        unsigned int columnas;
        int grilla[MAX_FILA][MAX_COL];
        unsigned int ancho;

        void inicializarObstaculos(void);

    public:
        bool checkColision(int pelotaX, int pelotaY);
        void dibujar(void);

};

#endif // OBSTACULO_H_INCLUDED
