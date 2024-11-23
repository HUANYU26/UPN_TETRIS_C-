#include "block.h"

Block::Block()
{
    cellSize = 30;//Establece el tamaño de cada celda en el bloque
    rotationState = 0; //Inicializa el estado de rotación del bloque en 0
    colors = GetCellColors(); //Obtiene los colores para las celdas del bloque
    rowOffset = 0; //Inicializa el desplazamiento de filas en 0
    columnOffset = 0; //Inicializa el desplazamiento de columnas en 0

}
//Este método se encarga de dibujar el bloque en la pantalla, dado un desplazamiento en las coordenadas offsetX y offsetY
void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}
//Este método permite mover el bloque en la cuadrícula
void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}
//Este método obtiene las posiciones de las celdas del bloque, teniendo en cuenta su rotación y desplazamiento
std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

//Este método rota el bloque e Incrementa el estado de rotación
void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}
//Este método deshace una rotación del bloque y Decrementa el estado de rotación
void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}

