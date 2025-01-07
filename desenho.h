#ifndef DESENHO_H
#define DESENHO_H

#include "raylib.h"
#include "TADs.h"
#include "atualiza_rodada.h"
#define LARGURA_CARTA 82
#define ALTURA_CARTA 130
#define ESPACO_CORTE 4

// Função para desenhar uma carta na tela
void desenharCarta(Texture2D textura, const Carta* carta, Vector2 posicao);
// Funções para inicializar e desenhar botões
void desenhaMenu(Texture2D FUNDO, Texture2D b1, Texture2D b2, Texture2D b3, Texture2D b4, Rectangle A, Rectangle B, Rectangle V, Rectangle D);
void desenhaPause();
void desenhaExit();

#endif

