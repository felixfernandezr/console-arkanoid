#include "Juego.h"
#include <iostream>
#include <conio.h>
#include "Utils.h"

// Constructor
Juego::Juego(): barra(40), obstaculos(4), finDelJuego(false) // Initialize with Bar in axis x=40 and Obstacles width = 4
{
    this->puntaje = 0; // Score and record = 0
    this->record = 0;
    this->vidas = 3;
}

void Juego::juegoLoop()
{
    // Do while true
    while(true)
    {
        // Game Setup
        system("cls");
        std::cout << "Score: " << this->puntaje << "     " << "Record: " << this->record << "     " << "Vidas: " << this->vidas << std::endl; // Score Display


        this->obstaculos.dibujar(); // Draw Obstacles
        //this->cancha.delinear(); // Deprecated due to performance issues
        this->pelota.dibujar(); // Draw ball
        this->barra.dibujar(); // Draw bar
        this->pelota.mover(); // Move ball position

        // Checking for key presses
        if (_kbhit())
        {
            char tecla = _getch();

            switch(tecla)
            {
            case 'x':
                funcionSalirRecursi();
                break;
            case 'p':
                funcionPausaRecursi(); // Pause function
                break;
            default:
                this->barra.hitTecla(tecla); // Bar movement handling
            }
        }

        // Call to game-logic boolean function, using object references
        this->finDelJuego = this->logica.juegoUpdate(&this->pelota, &this->barra, &this->obstaculos, &this->puntaje, &this->record, &this->vidas);

        if(finDelJuego) // If true break loop

            break;

        for(unsigned int d=0;d<10000000;d++); // Sleep for-loop
    }
}

void Juego::funcionPausaRecursi()
{
    // Position cursor and printing for text in Y = 11 and X = 25
    std::cout << "\033[11;25H"; // ANSI code for positioning cursor
    std::cout << "GAME PAUSED";
    std::cout.flush();

    // Position cursor and printing for text in Y = 12 and X = 20
    std::cout << "\033[12;20H";
    std::cout << "(Press 'p' to Return)";
    std::cout.flush();


    char tecla = _getch(); // Wait for user input

    if (tecla == 'p')
    {
        // Errasing messages from screen
        std::cout << "\033[11;24H" << "            ";
        std::cout.flush();
        std::cout << "\033[12;20H" << "                      ";
        std::cout.flush();
        Utils::cuentaRegresivaRecursi(3); // Countdown
    }
    else
        funcionPausaRecursi(); // Recursive call if user presses other key

}

void Juego::funcionSalirRecursi()
{
    // Position cursor and printing for text in Y = 11 and X = 2
    std::cout << "\033[11;7H"; // ANSI code for positioning cursor
    std::cout << "You're Exiting to the Main Menu. Are You Sure?";
    std::cout.flush();

    // Position cursor and printing for text in Y = 12 and X = 19
    std::cout << "\033[12;19H"; // ANSI code for positioning cursor
    std::cout << "All Data Will Be Lost";
    std::cout.flush();

    // Position cursor and printing for text in Y = 13 and X = 15
    std::cout << "\033[13;8H"; // ANSI code for positioning cursor
    std::cout << "Press 'y' to exit or 'n' to continue playing.";
    std::cout.flush();

    char tecla = _getch(); // Wait for user input

    // Errasing messages from screen
    std::cout << "\033[11;6H" << "                                                ";
    std::cout.flush();
    std::cout << "\033[12;18H" << "                       ";
    std::cout.flush();
    std::cout << "\033[13;7H" << "                                              ";
    std::cout.flush();

    if (tecla == 'y')
        throw std::exception(); // Exit to main menu
    else if (tecla == 'n')
        funcionPausaRecursi(); // Call to pause
    else
        funcionSalirRecursi(); // Recursive call if user presses other key
}











