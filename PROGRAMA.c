#include "raylib.h"
#define TELA 900
int main(void)
{
    InitWindow(TELA,TELA, "TRABALHO FINAL");
    ToggleFullscreen();
    Image img = LoadImage("mesa-UNO.png");// Carrega a imagem
    Texture2D textura = LoadTextureFromImage(img);  // Converte imagem em textura
    UnloadImage(img);  // Descarrega a imagem após carregar a textura
    // Define o modo de exibição (sem limites de FPS)
    SetTargetFPS(60);

    // Loop principal
    while (!WindowShouldClose())
    {
        // Inicia o desenho
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Desenha a textura na tela
        DrawTexture(textura, 100, 100, WHITE);

        // Finaliza o desenho
        EndDrawing();
    }

    // Libera os recursos
    UnloadTexture(textura);  // Descarrega a textura
    CloseWindow();  // Fecha a janela

    return 0;
}


