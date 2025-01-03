#include "cartas.h"
#include <stdlib.h>
#include <time.h>

// Funções para manipulação de cartas
CorCarta gerarCorAleatoria() {
    return (CorCarta)(rand() % 5);
}

int gerarNumeroAleatorio() {
    return rand() % 9 + 1;
}

Info gerarCartaNormal() {
    return (Info){gerarNumeroAleatorio(), gerarCorAleatoria()};
}

void gerarBaralho(CartaPilha baralho[], int tamanho) {
    int index = 0;
    for (int cor = 0; cor < 5; cor++) {
        for (int numero = 1; numero <= 9; numero++) {
            if (index >= tamanho) return;
            baralho[index++] = (CartaPilha){{numero, (CorCarta)cor}, NULL};
        }
    }
}

void embaralharBaralho(CartaPilha baralho[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        CartaPilha temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuirCartas(CartaPilha baralho[], int tamanho, Jogador* jogador) {
    for (int i = 0; i < CARTAS_INICIAIS && i < tamanho; i++) {
        insereInicioMao(jogador->mao, baralho[i].info);
    }
}

void desenharCarta(Texture2D textura, const Carta* carta, Vector2 posicao) {
    int linha = 0; // Variável para armazenar a linha baseada na cor

    // Determinar a linha correspondente à cor da carta
    switch (carta->info.cor) {
        case VERMELHO:
            linha = 0;
            break;
        case AMARELO:
            linha = 1;
            break;
        case VERDE:
            linha = 2;
            break;
        case AZUL:
            linha = 3;
            break;

    }

    // Criar o retângulo de origem baseado no número e na linha da cor
    Rectangle srcRec = {
        carta->info.num * (LARGURA_CARTA + ESPACO_CORTE), // Coluna baseada no número da carta
        linha * (ALTURA_CARTA + ESPACO_CORTE),           // Linha baseada na cor
        LARGURA_CARTA,                                   // Largura da carta
        ALTURA_CARTA                                     // Altura da carta
    };

    // Desenhar a carta na posição desejada
    DrawTextureRec(textura, srcRec, posicao, WHITE);
}
