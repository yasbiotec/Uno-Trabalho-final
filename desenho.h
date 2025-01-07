#ifndef DESENHO_H
#define DESENHO_H

#include "raylib.h"

// Funções para inicializar e desenhar botões
void initButtons();
void drawButton(Rectangle button, Texture2D texture, const char* label);
int isButtonClicked(Rectangle button);

#endif

