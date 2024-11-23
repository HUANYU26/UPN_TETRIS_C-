
#pragma once  //Directiva del preprocesador que garantiza que el archivo de encabezado

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

//Es el constructor que se encargará de inicializar una nueva instancia de un bloque con valores predeterminados
class Block
{
public:
    Block();
    int id;
 
   //Este método se encarga de dibujar el bloque en la pantalla o en la interfaz gráfica
    void Draw(int offsetX, int offsetY); 

    //Este método mueve el bloque en la cuadrícula del juego, cambiando su posición en las filas y columnas
    void Move(int rows, int columns); 

    //Este método devuelve un vector de Position que representa las posiciones de las celdas
    std::vector<Position> GetCellPositions(); 

    void Rotate(); //Este método se encarga de rotar el bloque
    void UndoRotation(); //Este método deshace una rotación previamente realizada

    std::map<int, std::vector<Position>> cells;

private:
    int cellSize; //Tamaño de cada celda del bloque
    int rotationState;
    std::vector<Color> colors; //Un vector que almacena los colores del bloque

    ////Los desplazamientos en filas y columnas de las celdas del bloque
    int rowOffset; 
    int columnOffset;

};
