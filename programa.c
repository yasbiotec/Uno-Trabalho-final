#include "raylib.h"
#include "atualiza_rodada.h"
#define TELA 750

typedef enum { MENU, GAME, PAUSE, EXIT } gameScreen;

void initGame();// funcao que inicia todas as variaveis/estruturas utilizadas no funcionamento interno
Jogador jogador_atual = ListaJogadores->prim; //ponteiro que aponta para o primeiro jogador da lista
void desenhaMenu(Texture2D background, Texture2D b1, Texture2D b2, Texture2D b3, Texture2D b4, Rectangle Novo_jogo, Rectangle Continuar, Rectangle Ranking, Rectangle Sair);
void desenhaPause();
void desenhaExit();

int main() {
    InitWindow(TELA, TELA, "----------------------------------------------------UNO!--------------------------------");
    SetTargetFPS(60);

    // Inicializa variáveis
    gameScreen currentScreen = MENU;
    int pause = 0;

    // Inicializa texturas e botões
    Texture2D background = LoadTexture("fundo_principal.png");
    Texture2D b1 = LoadTexture("botao1.png");
    Texture2D b2 = LoadTexture("botao2.png");
    Texture2D b3 = LoadTexture("botao3.png");
    Texture2D b4 = LoadTexture("botao4.png");

    Rectangle Novo_jogo = {200, 310, b1.width, b1.height};
    Rectangle Continuar = {200, 410, b2.width, b2.height};
    Rectangle Ranking = {200, 510, b3.width, b3.height};
    Rectangle Sair = {200, 610, b4.width, b4.height};

    initGame();

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        switch (currentScreen) {
            case MENU:
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (CheckCollisionPointRec(mousePos, Novo_jogo)) {
                        printf("Novo Jogo iniciado!\n");
                        currentScreen = GAME;
                    } else if (CheckCollisionPointRec(mousePos, Continuar)) {
                        printf("Continuar jogo!\n");
                        currentScreen = GAME;
                    } else if (CheckCollisionPointRec(mousePos, Ranking)) {
                        printf("Visualizar Ranking!\n");
                    } else if (CheckCollisionPointRec(mousePos, Sair)) {
                        currentScreen = EXIT;
                    }
                }

                BeginDrawing();
                desenhaMenu(background, b1, b2, b3, b4, Novo_jogo, Continuar, Ranking, Sair);
                EndDrawing();
                break;

            case GAME:
                if (IsKeyPressed(KEY_P)) {
                    pause = 1;
                    currentScreen = PAUSE;
                }
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Jogo em andamento...", 100, 100, 30, BLACK);
                atualizaRodada(pilhaMesa, baralho, jogador_atual);
                desenhaRodada(pilhaMesa, ls_jogadores);
                EndDrawing();
                break;

            case PAUSE:
                if (IsKeyPressed(KEY_P)) {
                    pause = 0;
                    currentScreen = GAME;
                }
                BeginDrawing();
                desenhaPause();
                EndDrawing();
                break;

            case EXIT:
                CloseWindow();
                return 0;
        }
    }

    // Libera recursos
    UnloadTexture(b1);
    UnloadTexture(b2);
    UnloadTexture(b3);
    UnloadTexture(b4);
    UnloadTexture(background);
    CloseWindow();

    return 0;
}

void initGame() {
    // Inicializa variáveis ou estruturas do jogo
    printf("Jogo inicializado!\n");
}

