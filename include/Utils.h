#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <thread>
#include <chrono>
#include "Dupla.h"

class Utils
{
    public:
        static void sleepSegundos(unsigned int segundos);
        static void cuentaRegresivaRecursi(unsigned int inicio);
};

#endif // UTILS_H_INCLUDED
