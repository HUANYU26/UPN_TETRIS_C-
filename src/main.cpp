#include "raylib.h" //Incluye la biblioteca Raylib, una librería de desarrollo de juegos de código abierto.
#include "game.h"
#include "colors.h"
#include <iostream>

//Esta función se utiliza para detectar si ha pasado un cierto intervalo de tiempo desde la última vez que se llamó
double lastUpdateTime = 0;//Se compara la diferencia entre el tiempo actual y el último tiempo registrado

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "raylib Tetris");//Inicialización de la ventana
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);//Carga de fuente

    Game game = Game();
     
    while (WindowShouldClose() == false)
    {
       // Actualizar la lógica del juego
        UpdateMusicStream(game.music);

        game.HandleInput(); //El propósito de esta función es gestionar la entrada del jugador procesar teclado
        if (EventTriggered(0.2))
        {
        game.MoveBlockDown(); //El propósito de este método es mover la pieza activa 
        }

        BeginDrawing();  // Inicia el proceso de renderizado en la ventana del juego
        
        ClearBackground(darkBlue);//Limpia y Establece el color de fondo de la pantalla

        //Dibuja el texto "Score" en la pantalla, que típicamente se usa para mostrar la etiqueta de puntaje en la interfaz del juego
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);

        //Dibuja el texto "Nest", que normalmente hace referencia a la próxima pieza de Tetris que caerá.
        DrawTextEx(font, "Nest", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            //Muestra un mensaje de "GAME OVER" para indicar que la partida ha finalizado
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        // Dibuja un fondo visual para el puntaje del jugador
        DrawRectangleRounded({320, 55, 170, 60}, 0.3,6, lightBlue);

       //Preparar un espacio en memoria para guardar el puntaje del jugador en formato de texto (
        char scoreText[10];

        //Convierte el puntaje del jugador de un número entero a una cadena de caracteres
        sprintf(scoreText, "%d", game.score);

        //Calcular el ancho y la altura del texto que representará el puntaje, para centrarlo correctamente en el rectángulo
        Vector2 TextSize = MeasureTextEx(font, scoreText, 38,2);

        //Dibujar el puntaje del jugador centrado en el panel de puntaje en la pantalla
        DrawTextEx(font, scoreText, {320 + (170 - TextSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3,6, lightBlue);
        game.Draw(); // Dibujar la interfaz gráfica del juego
        EndDrawing(); // Mostrar la pantalla
    }

    CloseWindow();
}
