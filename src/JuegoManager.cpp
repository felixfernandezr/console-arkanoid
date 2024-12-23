#include "JuegoManager.h"
#include <iostream>
#include <conio.h>

#include "Juego.h"

// Class constructor
JuegoManager::JuegoManager() : nivelActual(1) // Setting level to first
{
    this->estadoActual = EstadoJuego::MenuInico; // First state start menu
    this->gameOver = false;
}

// This function serves as a state handler for the game
void JuegoManager::jugar()
{
    while(!this->gameOver) // Done while gameOver is false
    {
        switch(this->estadoActual)
        {
            case EstadoJuego::MenuInico:
                this->mostrarMenuInicio(); // call to "ui" function
                this->cambiarEstado(EstadoJuego::Play);
                break;
            case EstadoJuego::Play:

                if (this->nivelActual == 1) {
                    this->inicializarNivel(); // // Level handling and initialize obstacles
                    this->juego.juegoLoop(); // Start actual game-loop
                }
                    system("cls"); // Level transition (beta)
                    std::cout << "GOOD ONE! Press any key for next level!" << std::endl;
                    system("pause");

                this->nivelActual++; // Level raise
                this->inicializarNivel(); // Level handling
                this->juego.pelota.reiniciar(); // Ball position reset
                this->juego.juegoLoop(); // Game-loop

                break;
            case EstadoJuego::PantallaFin:
                this->mostrarPantallaFin(); // Show end screen "ui"
                this->gameOver = true; // End game-manager loop and exit program
                break;
        }
    }
}

// Level handler
void JuegoManager::inicializarNivel() {
    switch (this->nivelActual) {
        case 1:
            this->juego.obstaculos.inicializarObstaculos(niveles.nivel1()); // Sends a template of obstacle distribution (check Niveles niveles.nivel1())
            break;
        case 2:
            this->juego.obstaculos.inicializarObstaculos(niveles.nivel2()); // This templates only have 1s and 0s
            break;
        case 3:
            this->juego.obstaculos.inicializarObstaculos(niveles.nivel3()); // Then randomized in Obstaculos obstaculos.inicializarObstaculos()
            break;
        default:
            cambiarEstado(EstadoJuego::PantallaFin); // No more levels. When level > 3 this catches game end
            break;
    }
}

 // Start screen UI
void JuegoManager::mostrarMenuInicio()
{
    system("cls");
    std::cout << "Welcome to the Game!" << std::endl;
    std::cout << "Press Any Key to Start" << std::endl;

    // Wait for user input to start the game
    _getch();
}

// End screem UI
void JuegoManager::mostrarPantallaFin()
{
    system("cls");
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your Score Was: " << this->juego.record << "!" << std::endl;
    std::cout << "Press Any Key to Exit" << std::endl;

    _getch();
}

// Change game state
void JuegoManager::cambiarEstado(EstadoJuego nuevoEstado)
{
    this->estadoActual = nuevoEstado;
}


