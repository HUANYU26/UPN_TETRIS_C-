#pragma once
#include <raylib.h>
#include <vector>

//Declaración de Colores Globales
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

//Tipo de retorno de la función es un vector de colores que se utilizarán para pintar las celdas
std::vector<Color> GetCellColors();
