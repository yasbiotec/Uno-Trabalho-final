#ifndef CARTAS_H
#define CARTAS_H

#include "raylib.h"
#include "TADs.h"

#define TELA 1000
#define CARTAS_INICIAIS 7
#define LARGURA_CARTA 82
#define ALTURA_CARTA 130
#define ESPACO_CORTE 4

//Gera cor aleatoria (amarelo,azul,verde e vermelho
CorCarta gerarCorAleatoria();
//Gera numero da carta de 0 a 9
int gerarNumeroAleatorio();
Info gerarCartaNormal();
//Gera baralho
void gerarBaralho(CartaPilha baralho[], int tamanho);
//Embaralha as cartas aleatorias
void embaralharBaralho(CartaPilha baralho[], int tamanho);
//Distribui elas
void distribuirCartas(CartaPilha baralho[], int tamanho, Jogador* jogador);
//desenha
void desenharCarta(Texture2D textura, const Carta* carta, Vector2 posicao);
#endif
