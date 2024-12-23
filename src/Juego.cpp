#include "Juego.h"
#include <iostream>
#include <conio.h>

Juego::Juego(): barra(40), obstaculos(4)
{
    this->puntaje = 0;
    this->record = 0;
}

void Juego::juegoLoop(void)
{
    this->obstaculos.inicializarObstaculos(this->niveles.nivel3());

    while(true)
    {
        // Game Setup
        system("cls");
        std::cout << "Score: " << this->puntaje << "     " << "Record: " << this->record << std::endl;
        //this->cancha.delinear();
        this->pelota.dibujar();
        this->barra.dibujar();
        this->obstaculos.dibujar();
        this->pelota.mover();

        // Checking for moving-key presses
        if(_kbhit())
        {
            barra.hitTecla(_getch());
            //if(_getch() == 't')

        }

        bool finDelJuego = this->logica.juegoUpdate(&this->pelota, &this->barra, &this->obstaculos, &this->puntaje, &this->record);

        if(finDelJuego)
            break;

        for(unsigned int d=0;d<10000000;d++); // Sleep for-loop
    }
}
