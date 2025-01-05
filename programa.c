#include "raylib.h"
#include "cartas.h"
#include <stdlib.h>
#include <time.h>

#define TAM_BARALHO 45

int main(void) {
    InitWindow(TELA, TELA, "Jogo de Cartas");
    Texture2D mesaTextura = LoadTexture("mesa-UNO.png");
    Texture2D cartasTextura = LoadTexture("cartas.png");
    Texture2D cartaImagem = LoadTexture("carta_maquina.png");  // Imagem de uma carta repetida para a máquina
    Texture2D baralhoimagem = LoadTexture("baralho.png");  // Imagem do botão para adicionar uma carta
    srand(time(NULL));

    CartaPilha baralho[TAM_BARALHO];
    gerarBaralho(baralho, TAM_BARALHO);
    embaralharBaralho(baralho, TAM_BARALHO);

    PilhaCartas* descarte = criaPilhaCartas();
    int topoBaralho = TAM_BARALHO;
    empilhaPilhaCartas(descarte, baralho[--topoBaralho].info);

    Vector2 posicaobaralho = {100, 200};  // Posição onde o botão vai ser desenhado


    Jogador jogador = {.mao = criaMao()};
    Jogador maquina = {.mao = criaMao()};

    distribuirCartas(baralho, topoBaralho, &jogador);
    distribuirCartas(baralho, topoBaralho, &maquina);

    SetTargetFPS(60);
    bool cartaClicada = false;
    Info cartaInfoClicada = {0, PRETA};

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        // Jogada do jogador
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Carta* cartaAtual = jogador.mao->prim;
            for (int i = 0; cartaAtual != NULL; i++) {
                Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 560};
                if (verificarCliqueCarta(mousePos, posicao)) {
                    if (cartaValida(cartaAtual->info, descarte->topo->info)) {
                        cartaInfoClicada = removeCartaMao(jogador.mao, cartaAtual);
                        empilhaPilhaCartas(descarte, cartaInfoClicada);
                        cartaClicada = true;
                    }
                    break;
                }
                cartaAtual = cartaAtual->prox;
            }

            // Verificar se o clique foi dentro da área do baralho
            if (mousePos.x >= posicaobaralho.x && mousePos.x <= posicaobaralho.x + baralhoimagem.width &&
                mousePos.y >= posicaobaralho.y && mousePos.y <= posicaobaralho.y + baralhoimagem.height) {
                // Adicionar uma carta aleatória à mão do jogador
                Info cartaAleatoria = gerarCartaNormal();
                insereInicioMao(jogador.mao, cartaAleatoria);
            }


        }

        // Jogada da máquina
        if (cartaClicada) {
            jogadaMaquina(&maquina, descarte, baralho, &topoBaralho);
            cartaClicada = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(mesaTextura, 0, 0, WHITE);
        DrawTexture(baralhoimagem, posicaobaralho.x, posicaobaralho.y, WHITE);

        // Desenhar pilha de descarte
        Vector2 posicaoDescarte = {360, 220};
        desenharCarta(cartasTextura, &(descarte->topo->info), posicaoDescarte);

        // Desenhar cartas do jogador
        Carta* cartaAtual = jogador.mao->prim;
        for (int i = 0; cartaAtual != NULL; i++) {
            Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 560};
            desenharCarta(cartasTextura, cartaAtual, posicao);
            cartaAtual = cartaAtual->prox;
        }

        // Desenhar quantidade de cartas da máquina
        int quantidadeCartasMaquina = 0;
        Carta* cartaMaquina = maquina.mao->prim;
        while (cartaMaquina != NULL) {
            quantidadeCartasMaquina++;
            cartaMaquina = cartaMaquina->prox;
        }

        // Desenhar as cartas da máquina como ícones repetidos
        for (int i = 0; i < quantidadeCartasMaquina; i++) {
            Vector2 posicaoMaquina = {100 + i * (LARGURA_CARTA + 1), 5};  // Ajuste de posição para as cartas da máquina com 1 pixel de espaçamento
            DrawTexture(cartaImagem, posicaoMaquina.x, posicaoMaquina.y, WHITE);
        }

        EndDrawing();
    }

    UnloadTexture(mesaTextura);
    UnloadTexture(cartasTextura);
    UnloadTexture(cartaImagem);
    CloseWindow();
    return 0;
}
