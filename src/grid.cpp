#include "grid.h"
#include <iostream>
#include "colors.h"

//El constructor inicializa los atributos de la clase Grid y llama a la función Initialize()
//que configura la grilla vacía, y a GetCellColors()
Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}
//Inicializa la grilla, llenándola con ceros. En el contexto de Tetris, un cero podría representar una celda vacía
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
        
    }

}

//Imprime el estado actual de la grilla en la consola
void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}
//Dibuja la grilla en la pantalla usando la biblioteca de gráficos.
void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);

        }
    }
}
//Verificar si una celda está fuera de los límites de la grilla
bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}
//Verificar si una celda está vacía.
bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}
//Elimina las filas completas y las mueve hacia abajo.
int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
         }
    }
    return completed;
}
//Verificar si una fila está llena.
bool Grid::IsRowFull(int row)
{
    for(int column = 0; column < numCols; column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}
//Limpia una fila de la grilla, poniéndola completamente vacía.
void Grid::ClearRow(int row)
{
    for(int column = 0; column < numCols; column++)
    {
        grid[row][column] == 0;
    }
}
//Mueve una fila hacia abajo y vacía la fila original
void Grid::MoveRowDown(int row, int numRows)
{
    for(int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
