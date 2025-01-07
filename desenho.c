#include "desenho.h"
#include "raylib.h"

// Vari�veis para armazenar as imagens dos bot�es
Texture2D startButtonTexture;
Texture2D exitButtonTexture;

// Inicializa os bot�es carregando as imagens
void initButtons() {
    startButtonTexture = LoadTexture("start_button.png"); // Substitua com o caminho da imagem do bot�o "Iniciar"
    exitButtonTexture = LoadTexture("exit_button.png");   // Substitua com o caminho da imagem do bot�o "Sair"
}

// Fun��o para desenhar um bot�o com a imagem fornecida
void drawButton(Rectangle button, Texture2D texture, const char* label) {
    // Desenha a textura na posi��o do bot�o
    DrawTextureRec(texture, (Rectangle){ 0, 0, texture.width, texture.height }, (Vector2){ button.x, button.y }, WHITE);

    // Desenha o texto no bot�o, centralizado
    Vector2 textSize = MeasureTextEx(GetFontDefault(), label, 20, 0);
    DrawText(label, button.x + (button.width - textSize.x) / 2, button.y + (button.height - textSize.y) / 2, 20, LIGHTGRAY);
}

// Verifica se um bot�o foi clicado
int isButtonClicked(Rectangle button) {
    Vector2 mousePoint = GetMousePosition();
    return CheckCollisionPointRec(mousePoint, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

