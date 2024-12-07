#include "Obstaculo.h"
#include <iostream>
#include <windows.h>

Obstaculo::Obstaculo(unsigned int filas, unsigned int columnas, unsigned int ancho)
{
    this->filas = filas;
    this->columnas = columnas;
    this->ancho = ancho;

    this->inicializarObstaculos();
}

void Obstaculo::inicializarObstaculos()
{
    for (int i = 0; i < this->filas; i++) {
        for (int j = 0; j < this->columnas; j++) {
            this->grilla[i][j] = rand() % 4; // Random strength (0 = no obstacle, 1-3 = obstacle strength)
        }
    }
}

bool Obstaculo::checkColision(int pelotaX, int pelotaY)
{
    for(int i = 0; i < this->filas; i++)
    {
        for(int j = 0; j < this->columnas; j++)
        {
            if(this->grilla[i][j] > 0) // If obstacle present
            {
                int inicioObsX = j * this->ancho; // X start position of obstacule
                int finObsX = inicioObsX + this->ancho; // X end position of current obstacle
                int obsY = i + 1; // Y position of current obstacle

                // Checking of ball hits obstacule
                if(pelotaX >= inicioObsX && pelotaX < finObsX && pelotaY == obsY)
                {
                    grilla[i][j]--; // Reducing obstacule strenght
                    return true;
                }
            }
        }
    }
    return false;
}



void Obstaculo::dibujar(void)
{
    for (int i = 0; i < this->filas; i++) {
        for (int j = 0; j < this->columnas; j++) {
            if (grilla[i][j] > 0) { // If there is an obstacle
                int inicioObsX = j * this->ancho;
                int obsY = i + 1;

                HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
                for (int k = 0; k < this->ancho; k++) {
                    //COORD dwPos = {static_cast<SHORT>(inicioObsX + k), static_cast<SHORT>(obsY)};
                    COORD dwPos;
                    dwPos.X = inicioObsX + k;
                    dwPos.Y= obsY;
                    SetConsoleCursorPosition(hcon, dwPos);

                    // Use different characters for different strengths
                    if (grilla[i][j] == 3)
                        std::cout << '#'; // Strong brick
                    else if (grilla[i][j] == 2)
                        std::cout << '@'; // Medium brick
                    else
                        std::cout << '.'; // Weak brick
                }
            }
        }
    }
}
