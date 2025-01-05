#include "jogo.h"
#include <stdlib.h>
#include <time.h>

// Função para verificar se a carta foi clicada
int verificarCliqueCarta(Vector2 mousePos, Vector2 posicaoCarta) {
    return (mousePos.x >= posicaoCarta.x && mousePos.x <= posicaoCarta.x + LARGURA_CARTA &&
            mousePos.y >= posicaoCarta.y && mousePos.y <= posicaoCarta.y + ALTURA_CARTA);
}

// Função para obter o nome da cor da carta
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

// Função para verificar se a carta é válida para jogar
int cartaValida(Info carta, Info topoDescarte) {
    return (carta.num == topoDescarte.num || carta.cor == topoDescarte.cor);
}

// Função para realizar a jogada da máquina
void jogadaMaquina(Jogador* maquina, PilhaCartas* descarte, CartaPilha baralho[], int* topoBaralho) {
    Carta* cartaAtual = maquina->mao->prim;
    while (cartaAtual != NULL) {
        if (cartaValida(cartaAtual->info, descarte->topo->info)) {
            Info cartaJogada = removeCartaMao(maquina->mao, cartaAtual);
            empilhaPilhaCartas(descarte, cartaJogada);
            return;
        }
        cartaAtual = cartaAtual->prox;
    }
    // Máquina compra uma carta se não tiver jogada válida
    if (*topoBaralho > 0) {
        insereInicioMao(maquina->mao, baralho[--(*topoBaralho)].info);
    }
}

// Função para gerenciar o jogo com várias máquinas
void gerenciarJogo(Jogador* jogador, Jogador* maquina1, Jogador* maquina2, PilhaCartas* descarte, CartaPilha baralho[], int* topoBaralho, Texture2D cartasTextura) {
    SetTargetFPS(60);
    bool cartaClicada = false;
    Info cartaInfoClicada = {0, PRETA};

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        // Jogada do jogador
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Carta* cartaAtual = jogador->mao->prim;
            for (int i = 0; cartaAtual != NULL; i++) {
                Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 560};
                if (verificarCliqueCarta(mousePos, posicao)) {
                    if (cartaValida(cartaAtual->info, descarte->topo->info)) {
                        cartaInfoClicada = removeCartaMao(jogador->mao, cartaAtual);
                        empilhaPilhaCartas(descarte, cartaInfoClicada);
                        cartaClicada = true;
                    }
                    break;
                }
                cartaAtual = cartaAtual->prox;
            }
        }

        // Jogadas das máquinas
        if (cartaClicada) {
            jogadaMaquina(maquina1, descarte, baralho, topoBaralho);
            jogadaMaquina(maquina2, descarte, baralho, topoBaralho);
            cartaClicada = false;
        }

        // Início do desenho
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Desenha a mesa
        Texture2D mesaTextura = LoadTexture("mesa-UNO.png");
        DrawTexture(mesaTextura, 0, 0, WHITE);
        UnloadTexture(mesaTextura);

        // Desenhar pilha de descarte
        Vector2 posicaoDescarte = {350, 200};
        desenharCarta(cartasTextura, &(descarte->topo->info), posicaoDescarte);

        // Desenhar cartas do jogador
        Carta* cartaAtual = jogador->mao->prim;
        for (int i = 0; cartaAtual != NULL; i++) {
            Vector2 posicao = {5 + i * (LARGURA_CARTA + 30), 560};
            desenharCarta(cartasTextura, cartaAtual, posicao);
            cartaAtual = cartaAtual->prox;
        }

        // Desenhar cartas das máquinas
        Carta* cartaAtualMaquina1 = maquina1->mao->prim;
        for (int i = 0; cartaAtualMaquina1 != NULL; i++) {
            Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 100}; // Alterei para uma linha diferente da do jogador
            desenharCarta(cartasTextura, cartaAtualMaquina1, posicao);
            cartaAtualMaquina1 = cartaAtualMaquina1->prox;
        }

        Carta* cartaAtualMaquina2 = maquina2->mao->prim;
        for (int i = 0; cartaAtualMaquina2 != NULL; i++) {
            Vector2 posicao = {6 + i * (LARGURA_CARTA + 30), 230}; // Linha diferente da máquina 1 e jogador
            desenharCarta(cartasTextura, cartaAtualMaquina2, posicao);
            cartaAtualMaquina2 = cartaAtualMaquina2->prox;
        }

        EndDrawing();
    }
}
