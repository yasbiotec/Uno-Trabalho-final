#ifndef DESENHO_H
#define DESENHO_H

#include "raylib.h"

// Fun��es para inicializar e desenhar bot�es
void initButtons();
void drawButton(Rectangle button, Texture2D texture, const char* label);
int isButtonClicked(Rectangle button);

#endif

