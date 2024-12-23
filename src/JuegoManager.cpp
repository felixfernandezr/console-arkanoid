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
                this->resetValores(); // reset level and score values to default
                this->cambiarEstado(EstadoJuego::Play);
                break;
            case EstadoJuego::Play:
                    /*system("cls");
                    std::cout << "pre nivelActual: " << nivelActual << std::endl;
                    system("pause");*/

                this->inicializarNivel(); // Level handling
                this->juego.juegoLoop(); // Game-loop
                this->juego.pelota.reiniciar(); // Ball position reset
                this->nivelActual++; // Level raise

                if(this->nivelActual < 5) // Compares to 5 because nivelActual is raised before if statement
                {
                    this->cambiarEstado(EstadoJuego::NivelCompleto);
                }
                else {
                    this->cambiarEstado(EstadoJuego::FinDelJuego);
                }
                /*system("cls");
                std::cout << "post nivelActual: " << nivelActual << std::endl;
                system("pause");*/

                break;
            case EstadoJuego::NivelCompleto:
                    /*system("cls");
                    std::cout << "EstadoJuego::NivelCompleto" << std::endl;
                    system("pause");*/
                this->mostrarNivelCompleto();
                this->cambiarEstado(EstadoJuego::Play);
                break;
            case EstadoJuego::GameOver:
                    /*system("cls");
                    std::cout << "EstadoJuego::GameOver" << std::endl;
                    system("pause");*/
                this->mostrarGameOver(); // Show game over "ui"
                this->cambiarEstado(EstadoJuego::MenuInico);
                //this->gameOver = true; // End game-manager loop and exit program
                break;
            case EstadoJuego::FinDelJuego:
                this->mostrarPantallaFin(); // Show end screen "ui"
                this->mostrarCreditos(); // Show game credits
                this->cambiarEstado(EstadoJuego::MenuInico);
                //this->gameOver = true;// End game-manager loop and exit program
                break;
        }
    }
}

// Level handler
void JuegoManager::inicializarNivel() {
    switch (this->nivelActual) {
        case 1:
                /*system("cls");
                std::cout << "case 1" << std::endl;
                system("pause");*/
            this->juego.obstaculos.inicializarObstaculos(niveles.nivel1()); // Sends a template of obstacle distribution (check Niveles niveles.nivel1())
            break;
        case 2:
                /*system("cls");
                std::cout << "case 2" << std::endl;
                system("pause");*/
            this->juego.obstaculos.inicializarObstaculos(niveles.nivel2()); // This templates only have 1s and 0s
            break;
        case 3:
                /*system("cls");
                std::cout << "case 3" << std::endl;
                system("pause");*/
            this->juego.obstaculos.inicializarObstaculos(niveles.nivel3()); // Then randomized in Obstaculos obstaculos.inicializarObstaculos()
            break;
        default:
                /*system("cls");
                std::cout << "default" << std::endl;
                system("pause");*/
            cambiarEstado(EstadoJuego::GameOver); // No more levels. When level > 3 this catches game end
            break;
    }
}

 // Start screen UI
void JuegoManager::mostrarMenuInicio()
{
    system("cls");
    std::cout << "Welcome to the Game!" << std::endl;
    std::cout << "Press Any Key to Start" << std::endl;

    // Wait for user input
    _getch();
}

void JuegoManager::mostrarNivelCompleto()
{
    system("cls");
    std::cout << "Well Done! You Completed Level " << this->nivelActual - 1 << "!" << std::endl;
    std::cout << "Your Score is Currently " << this->juego.record << "!" << std::endl;
    std::cout << "Press Any Key to Continue" << std::endl;

    // Wait for user input
    _getch();
}

// End screem UI
void JuegoManager::mostrarGameOver()
{
    system("cls");
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your Best Score Was: " << this->juego.record << "!" << std::endl;
    std::cout << "Press Any Key to Exit" << std::endl;

    // Wait for user input
    _getch();
}

void JuegoManager::mostrarPantallaFin()
{
    system("cls");
    std::cout << "Congratulations! You Won the Game!" << std::endl;
    std::cout << "Your Best Score Was: " << this->juego.record << "!" << std::endl;
    std::cout << "Press Any Key and Go to Credits" << std::endl;

    // Wait for user input
    _getch();
}

void JuegoManager::mostrarCreditos()
{
    system("cls");
    std::cout << "A JKNBH777 Creation" << std::endl;
    std::cout << "Press Any Key and Go to Main Menu" << std::endl;

    // Wait for user input
    _getch();
}

// Change game state
void JuegoManager::cambiarEstado(EstadoJuego nuevoEstado)
{
    this->estadoActual = nuevoEstado;
}
//Reset game default values
void JuegoManager::resetValores()
{
    this->nivelActual = 1;
    this->juego.puntaje = 0;
    this->juego.record = 0;
}

