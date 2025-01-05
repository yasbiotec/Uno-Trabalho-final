#ifndef JOGO_H
#define JOGO_H

#include "raylib.h"
#include "cartas.h"
#include "TADs.h"

// Função para verificar se a carta foi clicada
int verificarCliqueCarta(Vector2 mousePos, Vector2 posicaoCarta);

// Função para obter o nome da cor da carta
const char* obterNomeCor(CorCarta cor);

// Função para verificar se a carta é válida para jogar
int cartaValida(Info carta, Info topoDescarte);

// Função para realizar a jogada da máquina
void jogadaMaquina(Jogador* maquina, PilhaCartas* descarte, CartaPilha baralho[], int* topoBaralho);

// Função para gerenciar o jogo com várias máquinas
void gerenciarJogo(Jogador* jogador, Jogador* maquina1, Jogador* maquina2, PilhaCartas* descarte, CartaPilha baralho[], int* topoBaralho, Texture2D cartasTextura);

#endif
