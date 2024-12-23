#include "EstadoManager.h"
#include <iostream>

EstadoManager::EstadoManager() {}

void EstadoManager::cambiarEstado(EstadoJuego nuevoEstado)
{
    this->estadoActual = nuevoEstado;
}

EstadoJuego EstadoManager::getEstadoActual()
{
    return this->estadoActual;
}
