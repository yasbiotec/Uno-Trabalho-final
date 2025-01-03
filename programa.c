#include "raylib.h"
#include "cartas.h"
#include <stdlib.h>
#include <time.h>

#define TAM_BARALHO 45

int verificarCliqueCarta(Vector2 mousePos, Vector2 posicaoCarta) {
    return (mousePos.x >= posicaoCarta.x && mousePos.x <= posicaoCarta.x + LARGURA_CARTA &&
            mousePos.y >= posicaoCarta.y && mousePos.y <= posicaoCarta.y + ALTURA_CARTA);
}

const char* obterNomeCor(CorCarta cor) {
    switch (cor) {
        case AMARELO: return "Amarelo";
        case VERDE: return "Verde";
        case VERMELHO: return "Vermelho";
        case AZUL: return "Azul";
        case PRETA: return "Preta";
        default: return "Desconhecida";
    }
}

int main(void) {
    InitWindow(TELA, TELA, "Jogo de Cartas");
    Texture2D mesaTextura = LoadTexture("mesa-UNO.png");
    Texture2D cartasTextura = LoadTexture("cartas.png");
    srand(time(NULL));

    CartaPilha baralho[TAM_BARALHO];
    gerarBaralho(baralho, TAM_BARALHO);
    embaralharBaralho(baralho, TAM_BARALHO);

    Jogador jogador = {.mao = criaMao()};
    distribuirCartas(baralho, TAM_BARALHO, &jogador);

    SetTargetFPS(60);
    bool cartaClicada = false;
    Info cartaInfoClicada = {0, PRETA};

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Carta* cartaAtual = jogador.mao->prim;
            for (int i = 0; cartaAtual != NULL; i++) {
                Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 560};
                if (verificarCliqueCarta(mousePos, posicao)) {
                    cartaInfoClicada = cartaAtual->info;
                    removeCartaMao(jogador.mao, cartaAtual);
                    cartaClicada = true;
                    break;
                }
                cartaAtual = cartaAtual->prox;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(mesaTextura, 0, 0, WHITE);

        Carta* cartaAtual = jogador.mao->prim;
        for (int i = 0; cartaAtual != NULL; i++) {
            Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 560};
            desenharCarta(cartasTextura, cartaAtual, posicao);
            cartaAtual = cartaAtual->prox;
        }

        if (cartaClicada) {
            char mensagem[50];
            snprintf(mensagem, sizeof(mensagem), "Cor: %s, Numero: %d",
                     obterNomeCor(cartaInfoClicada.cor), cartaInfoClicada.num);
            DrawText(mensagem, 350, 350, 20, BLACK);
        }

        EndDrawing();
    }

    UnloadTexture(mesaTextura);
    UnloadTexture(cartasTextura);
    CloseWindow();
    return 0;
}
