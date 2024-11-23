#pragma once
#include "grid.h"
#include "blocks.cpp"

//Declaración de la Clase 
class Game
{
public:
    Game();//Constructor de la clase
    ~Game(); //Destructor de la clase
    void Draw(); //Dibuja los elementos del juego en la pantalla
    void HandleInput();//Maneja la entrada del usuario (teclas presionadas)
    void MoveBlockDown();//Mueve el bloque actual hacia abajo
    bool gameOver;//variable booleana que indica si el juego ha terminado
    int score; //Variable entera que almacena la puntuación del jugador
    Music music;//Variable para manejar la música de fondo


private:
    void MoveBlockLeft(); //Mueve el bloque actual hacia la izquierda
    void MoveBlockRight();//Mueve el bloque actual hacia la derecha
    Block GetRandomBlock();//Obtiene un bloque aleatorio de la lista de bloques disponibles
    std::vector<Block> GetAllBlocks();//Obtiene una lista con todos los tipos de bloques posibles
    bool IsBlockOutside();// Comprueba si el bloque actual está fuera de los límites de la cuadrícula
    void LockBlock();//Fija el bloque actual en la cuadrícula
    bool BlockFits();//Comprueba si el bloque actual encaja en su posición actual
    void RotateBlock();//Rota el bloque actual
    void Reset();//Reinicia el juego
    void UpdateScore(int linesCleared, int moveDownPoints);//Actualiza la puntuación del jugador
    Grid grid;//Objeto de la clase Grid que representa la cuadrícula del juego
    std::vector<Block> blocks;//Vector de bloques que contiene los diferentes tipos de bloques
    Block currentBlock;//Bloque actual que está cayendo
    Block nextBlock;//Próximo bloque que aparecerá
    Sound rotateSound;//Sonido de rotación del bloque
    Sound clearSound;//Sonido de eliminación de líneas

};
