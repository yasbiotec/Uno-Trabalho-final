#ifndef CARTAS_H
#define CARTAS_H

#include "raylib.h"
#include "TADs.h"

#define TELA 797
#define CARTAS_INICIAIS 7
#define LARGURA_CARTA 81
#define ALTURA_CARTA 129
#define ESPACO_CORTE 5

// Prototipação de funções
CorCarta gerarCorAleatoria();
int gerarNumeroAleatorio();
Info gerarCartaNormal();
void gerarBaralho(CartaPilha baralho[], int tamanho);
void embaralharBaralho(CartaPilha baralho[], int tamanho);
void distribuirCartas(CartaPilha baralho[], int tamanho, Jogador* jogador);
void desenharCarta(Texture2D textura, const Carta* carta, Vector2 posicao);

#endif
