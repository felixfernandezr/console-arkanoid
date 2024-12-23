#include "Utils.h"
#include <iostream>
#include <thread>
#include <chrono>

// Sleep for a given number of seconds
void Utils::sleepSegundos(unsigned int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
}

// Static function to show a countdown in the middle of the screen
void Utils::cuentaRegresivaRecursi(unsigned int inicio)
{
    if(inicio <= 0) return;
    // Position cursor and printing for text in Y = 11 and X = 20
    std::cout << "\033[11;20H"; // ANSI code for positioning cursor
    std::cout << "Returning to Game In:";
    std::cout.flush();
    // Moving cursor to Y = 12 and X = 30
    std::cout << "\033[12;30H";
    std::cout << inicio; // Print countdown number
    std::cout.flush();  // Renders number before anything else on screen
    sleepSegundos(1); // Sleep for 1 second before showing the next number

    // Errasing messages from screen
    std::cout << "\033[11;19H" << "                      ";
    std::cout.flush();
    std::cout << "\033[12;29H" << "   ";
    std::cout.flush();

    cuentaRegresivaRecursi(inicio - 1); // Recursive call with counter decreased by 1
}




