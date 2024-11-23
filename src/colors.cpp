// Incluir el archivo de cabecera que probablemente contiene la definición de la estructura Color
#include "colors.h"

// Definición de colores utilizando la estructura Color (probablemente RGBA, 
//donde R es el valor de rojo, G es el valor de verde, B es el valor de azul y A es la opacidad/transparencia)
const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {13, 64, 216, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

// Función que devuelve un vector con algunos de los colores previamente definidos
std::vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
