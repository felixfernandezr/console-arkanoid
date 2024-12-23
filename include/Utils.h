#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class Utils
{
    public:
        static void sleepSegundos(unsigned int segundos);
        static void cuentaRegresivaRecursi(unsigned int inicio);
        static void cargarConfiguracion(const std::string& filepath, std::map<std::string, int>& settings);
        static void mostrarArchivo(const std::string& filepath);
};

#endif // UTILS_H_INCLUDED
