#include "cartas.h"
#include <stdlib.h>
#include <time.h>

// Função para gerar uma cor aleatória
Cor gerarCorAleatoria() {
    Cor corAleatoria;

    // Atribui valores aleatórios para cada cor
    corAleatoria.AMARELO = rand() % 9 + 1;   // Gera um número entre 1 e 9 para o amarelo
    corAleatoria.VERDE = rand() % 9 + 1;      // Gera um número entre 1 e 9 para o verde
    corAleatoria.VERMELHO = rand() % 9 + 1;   // Gera um número entre 1 e 9 para o vermelho
    corAleatoria.AZUL = rand() % 9 + 1;       // Gera um número entre 1 e 9 para o azul

    return corAleatoria;
}

// Função para gerar um número de carta (de 1 a 9)
int gerarNumeroAleatorio() {
    return rand() % 9 + 1;  // Gera um número entre 1 e 9
}

// Função para gerar uma carta normal
Carta gerarCartaNormal() {
    Carta carta;
    carta.numero = gerarNumeroAleatorio();
    carta.cor = gerarCorAleatoria();
    return carta;
}

// Função para gerar o baralho completo
void gerarBaralho(Carta baralho[]) {
    int i = 0;
    // Gera cartas normais (1 a 9 de cada cor)
    for (int cor = 0; cor < 4; cor++) {
        for (int numero = 1; numero <= 9; numero++) {
            baralho[i].numero = numero;
            baralho[i].cor = gerarCorAleatoria();
            i++;
        }
    }
}

// Função para embaralhar o baralho
void embaralharBaralho(Carta baralho[]) {
    for (int i = 0; i < 36; i++) {
        int j = rand() % 36;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// Função para distribuir cartas para os jogadores
void distribuirCartas(Carta baralho[], MaoJogador *mao) {
    for (int i = 0; i < CARTAS_INICIAIS; i++) {
        mao->cartas[i] = baralho[i];
    }
    mao->contadorCartas = CARTAS_INICIAIS;  // Cada jogador recebe 7 cartas
}

// Função para desenhar a carta a partir da textura (recorte da imagem)
void desenharCarta(Texture2D cartasTextura, Carta carta, Vector2 posicao) {
    // Posição da carta na textura do PNG
    int coluna = carta.numero - 1;  // Cartas de 1 a 9
    int linha = carta.cor.AMARELO;   // A cor determina a linha, usando o valor de AMARELO da estrutura

    Rectangle srcRec = {
        coluna * (LARGURA_CARTA + ESPACO_CORTE),  // Largura da carta no PNG
        linha * (ALTURA_CARTA + ESPACO_CORTE),  // Altura da carta no PNG
        LARGURA_CARTA,                       // Largura da carta
        ALTURA_CARTA                       // Altura da carta
    };

    // Desenha a carta na tela
    DrawTextureRec(cartasTextura, srcRec, posicao, WHITE);
}
