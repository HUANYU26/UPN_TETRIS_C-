#pragma once
#include <vector>
#include <raylib.h>

//Declaración de la clase 
class Grid
{
public:
    Grid();//Constructor de la clase
    void Initialize();//Inicializa la cuadrícula, llenándola de ceros
    void Print();//Imprime la cuadrícula en la consola (para depuración)
    void Draw();//Dibuja la cuadrícula en la pantalla
    bool IsCellOutside(int row, int column);//Comprueba si una celda está fuera de los límites de la cuadrícula
    bool IsCellEmpty(int row, int column);//Comprueba si una celda está vacía
    int ClearFullRows();//Elimina las filas completas de la cuadrícula y devuelve el número de filas eliminadas
    int grid[20][10];//Matriz bidimensional que representa la cuadrícula del juego

private:
    bool IsRowFull(int row);//Comprueba si una fila está completamente llena
    void ClearRow(int row);//Elimina una fila completa
    void MoveRowDown(int row, int numRows);//Mueve una fila hacia abajo un número específico de filas
    int numRows;//Número de filas de la cuadrícula
    int numCols;//Número de columnas de la cuadrícula
    int cellSize;//Tamaño de cada celda de la cuadrícula
    std::vector<Color> colors;//Vector de colores para representar los diferentes tipos de bloques
};