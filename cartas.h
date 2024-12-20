#ifndef CARTAS_H
#define CARTAS_H
#include "raylib.h"

#define TELA 797
#define CARTAS_INICIAIS 7  // Cada jogador começa com 7 cartas
#define LARGURA_CARTA 81
#define ALTURA_CARTA 129
#define ESPACO_CORTE 5 //espaço para o corte da carta

// Estrutura para armazenar as cores
typedef struct {
    int AMARELO;
    int VERDE;
    int VERMELHO;
    int AZUL;
} Cor;

// Estrutura para armazenar as cartas do jogo
typedef struct {
    int numero;  // Cartas normais de 1 a 9
    Cor cor;     // Cores da carta
} Carta;

// Estrutura para a mão do jogador
typedef struct {
    int contadorCartas;  // Contador de cartas na mão
    Carta cartas[1000];    // Limite de cartas na mão
} MaoJogador;

// Função para gerar uma cor aleatória
Cor gerarCorAleatoria();

// Função para gerar um número de carta (de 1 a 9)
int gerarNumeroAleatorio();

// Função para gerar uma carta normal
Carta gerarCartaNormal();

// Função para gerar o baralho completo
void gerarBaralho(Carta baralho[]);

// Função para embaralhar o baralho
void embaralharBaralho(Carta baralho[]);

// Função para distribuir cartas para os jogadores
void distribuirCartas(Carta baralho[], MaoJogador *mao);

// Função para desenhar a carta a partir da textura (recorte da imagem)
void desenharCarta(Texture2D cartasTextura, Carta carta, Vector2 posicao);

#endif
