#include "Juego.h"
#include <iostream>
#include <conio.h>

// Constructor
Juego::Juego(): barra(40), obstaculos(4) // Initialize with Bar in axis x=40 and Obstacles width = 4
{
    this->puntaje = 0; // Score and record = 0
    this->record = 0;
}

void Juego::juegoLoop(void)
{
    // Do while true
    while(true)
    {
        // Game Setup
        system("cls");
        std::cout << "Score: " << this->puntaje << "     " << "Record: " << this->record << std::endl; // Score Display


        this->obstaculos.dibujar(); // Draw Obstacles
        //this->cancha.delinear(); // Deprecated due to performance issues
        this->pelota.dibujar(); // Draw ball
        this->barra.dibujar(); // Draw bar
        this->pelota.mover(); // Move ball position

        // Checking for moving-key presses
        char input;
        if(_kbhit())
        {
            input = _getch();
            barra.hitTecla(input);
        }

        // Call to game-logic boolean function, using object references
        bool finDelJuego = this->logica.juegoUpdate(&this->pelota, &this->barra, &this->obstaculos, &this->puntaje, &this->record);

        if(finDelJuego) // If true break loop
            break;

        for(unsigned int d=0;d<10000000;d++); // Sleep for-loop
    }
}
