#include "game.h"
#include <random>

//// Constructor de la clase Game
Game::Game()
{
    grid = Grid(); // Inicializa la grilla del juego

    // Crea una lista de todos los bloques posibles
    blocks = GetAllBlocks();
    // Obtiene un bloque aleatorio como bloque actual
    currentBlock = GetRandomBlock();
    // Obtiene un bloque aleatorio como próximo bloque
    nextBlock = GetRandomBlock();
    // Bandera para indicar si el juego ha terminado
    gameOver = false;
     // Puntuación del jugador
    score = 0;
    // Inicializa el dispositivo de audio
    InitAudioDevice();
    // Carga la música de fondo
    music = LoadMusicStream("Sounds/music.mp3");
    // Reproduce la música de fondo
    PlayMusicStream(music);
    // Carga el sonido de rotación de bloque
    rotateSound = LoadSound("Sounds/rotate.mp3");
    // Carga el sonido de limpieza de línea
    clearSound = LoadSound("Sounds/clear.mp3");


}
// Destructor de la clase Game
Game::~Game()

{
    UnloadSound(rotateSound);// Libera el sonido de rotación
    UnloadSound(clearSound);// Libera el sonido de limpieza de línea
    UnloadMusicStream(music);// Libera la música de fondo
    CloseAudioDevice();// Cierra el dispositivo de audio
}
// Obtiene un bloque aleatorio de la lista
Block Game::GetRandomBlock()
// Si la lista de bloques está vacía, la llena nuevamente
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
     // Genera un índice aleatorio dentro del rango de la lista
    int randomIndex = rand() % blocks.size();
    // Extrae el bloque del índice aleatorio
    Block block = blocks[randomIndex];
    // Elimina el bloque extraído de la lista para evitar repeticiones
    blocks.erase(blocks.begin() + randomIndex);
    return block;// Devuelve el bloque aleatorio
}
// Crea una lista con todos los bloques posibles del juego
std::vector<Block> Game::GetAllBlocks()

// Retorna un vector con objetos de tipo Block representando cada bloque 
// del juego (I, J, L, O, S, T, Z)
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}
// Dibuja la grilla, el bloque actual y el próximo bloque
void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11, 11);// Posición del bloque actual 
    switch (nextBlock.id)
    {
    case 3:
        nextBlock.Draw(255, 290);// Posición del próximo bloque
        break;

    case 4:
        nextBlock.Draw(255, 280);// Posición del próximo bloque
        break;
    default:

        nextBlock.Draw(270, 270);// Posición del próximo bloque por defecto
        break;
    }

}
// Maneja la entrada del jugador
void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();// Obtiene la tecla presionada

    // Si se presiona una tecla y el juego ha terminado, reinicia el juego
    if(gameOver && keyPressed !=0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
        case KEY_LEFT: // Tecla izquierda
            MoveBlockLeft();
            break;
        case KEY_RIGHT: // Tecla derecha
            MoveBlockRight();
            break;
        case KEY_DOWN: // Tecla abajo
            MoveBlockDown();
            UpdateScore(0,1); // Actualiza puntaje por mover hacia abajo
            break;
        case KEY_UP: // Tecla arriba
            RotateBlock();
            break;

        // ... agregar otros casos para otras teclas si es necesario
        
    }
}

//Esta función se encarga de mover el bloque actual una posición a la izquierda
void Game::MoveBlockLeft()
{
    if(!gameOver)
    {
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }

}

//Mueve el bloque actual una unidad a la derecha dentro de la cuadrícula del juego
void Game::MoveBlockRight()
{
    if(!gameOver) 
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }

}
//Mueve el bloque actual una unidad hacia abajo 
void Game::MoveBlockDown()
{
    if(!gameOver) 
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }

}
//Comprueba si alguna de las celdas ocupadas por el bloque actual se encuentra fuera de la cuadrícula del juego
bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}
//Gira el bloque actual en sentido horario
void Game::RotateBlock()
{   
    
    if(!gameOver) 

    //  Si el bloque se sale de la cuadrícula o no encaja en su nueva posición después de la rotación
    {
        currentBlock.Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
        else 
        {
            PlaySound(rotateSound);
        }
    }

}
//Fija el bloque actual en la cuadrícula del juego y prepara un nuevo bloque para que caiga

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles)
    {
        //Actualiza la celda correspondiente en la cuadrícula para que coincida con el ID del bloque actual 
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;//Asigna el siguiente bloque al bloque actual
    if(BlockFits() == false)//Comprueba si el nuevo bloque encaja en la cuadrícula
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock(); //Genera un nuevo bloque aleatorio
    int rowsCleared = grid.ClearFullRows();//comprueba si el nuevo bloque encaja en la cuadrícula
    if(rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
    
}
//Comprueba si todas las celdas que ocuparía el bloque actual están vacías en la cuadrícula del juego   
bool Game::BlockFits()
{ 
    std::vector<Position> tiles = currentBlock.GetCellPositions();//Obtiene las posiciones de todas las celdas del bloque actual    
    for(Position item: tiles)
    {
        if(grid.IsCellEmpty(item.row, item.column) == false)//Si la celda correspondiente en la cuadrícula no está vacía
        {
            return false;
        }
    }
    return true;
}
//Esta función se encarga de reiniciar el juego a su estado inicial
void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks(); //Reiniciar la lista de bloques
    //Generar nuevos bloques
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;//puntuacion del jugador
}
//Esta función se encarga de actualizar la puntuación del jugador en función de las líneas eliminadas y los movimientos hacia abajo
void Game::UpdateScore(int linesCleared, int moveDownPoints)
{   
    //Calcular puntos por líneas eliminadas
    switch  (linesCleared)
    {
        case 1:
            score += 100;
            break;
        case 2:

            score += 100;
            break;

        case 3:

            score += 100;
            break;
        default:
            break;
    }
    score += moveDownPoints;//Agregar puntos por movimientos hacia abajo
}
