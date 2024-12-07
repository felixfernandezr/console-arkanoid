#include "Juego.h"
#include <iostream>
#include <conio.h>

Juego::Juego(): barra(40), obstaculos(10, 15, 4)
{
    this->puntaje = 0;
    this->record = 0;
}

void Juego::jugar(void)
{
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
            barra.hitTecla(_getch());

        //this->logica.juegoUpdate(&this->pelota, &this->barra, &this->obstaculos, &this->puntaje, &this->record);

        for(unsigned int d=0;d<15000000;d++); // Sleep for-loop



        // Checking for obstacle collision
        if(this->obstaculos.checkColision(pelota.posX, pelota.posY))
        {
            pelota.rebotarY();
            this->puntaje += 10;
            if(this->puntaje > this->record)
                {
                    this->record = this->puntaje;
                }
        }


        // Colission Logic
        // Walls
        if(this->pelota.posY==0)
        {
            this->pelota.rebotarY();
        }
        if(this->pelota.posX==0 || this->pelota.posX==59)
        {
            this->pelota.rebotarX();
        }

        // Bar
        if(this->pelota.posY==this->barra.posY)
        {
            if(this->pelota.posX>=this->barra.posX && this->pelota.posX < this->barra.posX+this->barra.largo)
            {
                this->pelota.rebotarY();
            }
        }

        // Game Over
        if(this->pelota.posY==27)
        {
            this->pelota.reiniciar();
            this->puntaje = 0;
        }
    }
}
