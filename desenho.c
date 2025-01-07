#include "desenho.h"
#include "raylib.h"

// Variáveis para armazenar as imagens dos botões
Texture2D startButtonTexture;
Texture2D exitButtonTexture;

// Inicializa os botões carregando as imagens
void initButtons() {
    startButtonTexture = LoadTexture("start_button.png"); // Substitua com o caminho da imagem do botão "Iniciar"
    exitButtonTexture = LoadTexture("exit_button.png");   // Substitua com o caminho da imagem do botão "Sair"
}

// Função para desenhar um botão com a imagem fornecida
void drawButton(Rectangle button, Texture2D texture, const char* label) {
    // Desenha a textura na posição do botão
    DrawTextureRec(texture, (Rectangle){ 0, 0, texture.width, texture.height }, (Vector2){ button.x, button.y }, WHITE);

    // Desenha o texto no botão, centralizado
    Vector2 textSize = MeasureTextEx(GetFontDefault(), label, 20, 0);
    DrawText(label, button.x + (button.width - textSize.x) / 2, button.y + (button.height - textSize.y) / 2, 20, LIGHTGRAY);
}

// Verifica se um botão foi clicado
int isButtonClicked(Rectangle button) {
    Vector2 mousePoint = GetMousePosition();
    return CheckCollisionPointRec(mousePoint, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

