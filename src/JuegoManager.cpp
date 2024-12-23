#include "JuegoManager.h"
#include <iostream>
#include <conio.h>

#include "Juego.h"

JuegoManager::JuegoManager()
{
    this->estadoActual = EstadoJuego::MenuInico;
    this->gameOver = false;
}

void JuegoManager::jugar()
{
    while(!this->gameOver)
    {
        switch(this->estadoActual)
        {
            case EstadoJuego::MenuInico:
                this->mostrarMenuInicio();
                break;

            case EstadoJuego::Play:
                this->juego.juegoLoop();
                this->cambiarEstado(EstadoJuego::PantallaFin);
                break;

            case EstadoJuego::PantallaFin:
                this->mostrarPantallaFin();
                break;
        }
    }
}

void JuegoManager::mostrarMenuInicio()
{
    system("cls");
    std::cout << "Welcome to the Game!" << std::endl;
    std::cout << "Press Any Key to Start" << std::endl;

    // Wait for user input to start the game
    _getch();

    cambiarEstado(EstadoJuego::Play);

}

void JuegoManager::mostrarPantallaFin()
{
    system("cls");
    std::cout << "Game Over!" << std::endl;
    //std::cout << "Your Score: " << std::endl;
    std::cout << "Press Any Key to Exit" << std::endl;

    _getch();

    this->gameOver = true;
}

void JuegoManager::cambiarEstado(EstadoJuego nuevoEstado)
{
    //std::cout << "Changing state to: " << static_cast<int>(nuevoEstado) << std::endl;
    this->estadoActual = nuevoEstado;
}

