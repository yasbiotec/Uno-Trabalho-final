#include "raylib.h"
#include "cartas.h"
#include <time.h>

// Função para verificar se o mouse clicou em uma carta
int verificarCliqueCarta(Vector2 mousePos, Carta carta, Vector2 posicaoCarta) {
    // Verifica se a posição do mouse está dentro da área da carta
    if (mousePos.x >= posicaoCarta.x && mousePos.x <= posicaoCarta.x + LARGURA_CARTA &&
        mousePos.y >= posicaoCarta.y && mousePos.y <= posicaoCarta.y + ALTURA_CARTA) {
        return 1;  // Retorna 1 se a carta foi clicada
    }
    return 0;  // Retorna 0 se a carta não foi clicada
}

int main(void) {
    // Inicializa a janela e o Raylib
    InitWindow(TELA, TELA, "Jogo de Cartas");

    // Carrega a imagem da mesa e das cartas
    Texture2D mesaTextura = LoadTexture("mesa-UNO.png");
    Texture2D cartasTextura = LoadTexture("cartas.png");

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera o baralho e embaralha
    Carta baralho[36];
    gerarBaralho(baralho);
    embaralharBaralho(baralho);

    // Mão do jogador
    MaoJogador maoJogador;
    distribuirCartas(baralho, &maoJogador);

    // Define o modo de exibição (sem limites de FPS)
    SetTargetFPS(60);

    // Variável para mostrar a mensagem de clique
    bool cartaClicada = false;

    // Loop principal
    while (!WindowShouldClose()) {
        // Captura a posição do mouse
        Vector2 mousePos = GetMousePosition();

        // Verifica se o botão esquerdo do mouse foi pressionado
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Loop para verificar se o clique foi em alguma carta
            for (int i = 0; i < maoJogador.contadorCartas; i++) {
                Vector2 posicao = { 6 + i * (LARGURA_CARTA + 30), 560 };

                if (verificarCliqueCarta(mousePos, maoJogador.cartas[i], posicao)) {
                    cartaClicada = true;  // Marca que uma carta foi clicada
                }
            }
        }

        // Inicia o desenho
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Desenha a mesa de fundo
        DrawTexture(mesaTextura, 0, 0, WHITE);

        // Desenha as cartas do jogador com espaçamento
        for (int i = 0; i < maoJogador.contadorCartas; i++) {
            Vector2 posicao = { 6 + i * (LARGURA_CARTA + 30), 560 };
            desenharCarta(cartasTextura, maoJogador.cartas[i], posicao);
        }

        // Se uma carta foi clicada, desenha a mensagem
        if (cartaClicada) {
            DrawText("Carta clicada!", 350, 350, 20, WHITE);
        }

        // Finaliza o desenho
        EndDrawing();
    }

    // Libera os recursos
    UnloadTexture(mesaTextura);
    UnloadTexture(cartasTextura);
    CloseWindow();  // Fecha a janela

    return 0;
}
