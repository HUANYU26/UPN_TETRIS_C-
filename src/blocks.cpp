#include "block.h" //Incluir el archivo de cabecera de la clase base Block
#include "position.h" // Incluir el archivo de cabecera de la clase Position, que representa la posición de las celdas del bloque

// Clase LBlock, que representa un bloque con forma de "L"
class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1; // Asigna el identificador único 1 para este bloque
        // Define las cuatro posibles orientaciones del bloque "L"
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        Move(0, 3); // Mueve el bloque a la posición inicial (en este caso, mueve 3 unidades en el eje y)
    }
};

// Clase JBlock, que representa un bloque con forma de "J"
class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2; // Asigna el identificador único 2 para este bloque
        // Define las cuatro posibles orientaciones del bloque "J"
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        Move(0, 3);// Mueve el bloque a la posición inicial
    }
};

// Clase IBlock, que representa un bloque con forma de "I" (una línea recta)
class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3; // Asigna el identificador único 3 para este bloque

         // Define las cuatro posibles orientaciones del bloque "I"
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        Move(0, 3); // Mueve el bloque a la posición inicial
    }
};
// Clase OBlock, que representa un bloque con forma de "O" (cuadrado)
class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4; // Asigna el identificador único 4 para este bloque
        // El bloque "O" es simétrico y tiene solo una orientación
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        Move(0, 3);// Mueve el bloque a la posición inicial
    }
};
// Clase SBlock, que representa un bloque con forma de "S"
class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;// Asigna el identificador único 5 para este bloque
        // Define las cuatro posibles orientaciones del bloque "S"
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);// Mueve el bloque a la posición inicial
    }
};

// Clase TBlock, que representa un bloque con forma de "T"
class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;// Asigna el identificador único 6 para este bloque
         // Define las cuatro posibles orientaciones del bloque "T"
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);// Mueve el bloque a la posición inicial
    }
};

// Clase ZBlock, que representa un bloque con forma de "Z"
class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7; // Asigna el identificador único 7 para este bloque
        // Define las cuatro posibles orientaciones del bloque "Z"
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        Move(0, 3);// Mueve el bloque a la posición inicial
    }
};

