#include "desenho.h"


//-----------------------------------------MENU-----------------------------------------------------------------
void desenhaMenu(Texture2D background, Texture2D b1, Texture2D b2, Texture2D b3, Texture2D b4, Rectangle Novo_jogo, Rectangle Continuar, Rectangle Ranking, Rectangle Sair) {
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);

    DrawTexture(b1, Novo_jogo.x, Novo_jogo.y, WHITE);
    DrawTexture(b2, Continuar.x, Continuar.y, WHITE);
    DrawTexture(b3, Ranking.x, Ranking.y, WHITE);
    DrawTexture(b4, Sair.x, Sair.y, WHITE);

    DrawText("Novo Jogo", 250, 330, 50, BLACK);
    DrawText("Continuar", 250, 430, 50, BLACK);
    DrawText("Ranking", 270, 530, 50, BLACK);
    DrawText("Sair", 292, 630, 50, BLACK);
}

void desenhaPause() {
    ClearBackground(LIGHTGRAY);
    DrawText("Pause - Aperte 'P' para voltar ao jogo", 100, 100, 30, BLACK);
}

void desenhaExit() {
    ClearBackground(DARKGRAY);
    DrawText("Saindo do jogo...", 100, 100, 30, WHITE);
}


//----------------------------------------------------------------JOGO EM SI--------------------------------------------------------------------

// Função para desenhar uma carta na tela
void desenharCarta(Texture2D textura, const Carta* carta, Vector2 posicao) {
    int linha = 0; // Linha baseada na cor da carta
    int coluna = carta->info.num; // Coluna baseada no número da carta

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
        case PRETA:
            linha = 4; // Linha para cartas pretas
            break;
    }


    // Ajustar a coluna para números especiais 13 e 14
    if (carta->info.num >= 13 && carta->info.num <= 14) {
        coluna = 5; // Coluna especial para números 13 e 14
    } else if (linha == 4 && coluna > 2) {
        coluna = 3; // Limitar colunas a 0-2 na linha 4
    } else if (carta->info.num > 12) {
        coluna = 0; // Tratar valores inválidos como 0
    }

    // Criar o retângulo de origem baseado na coluna e na linha da carta
    Rectangle srcRec = {
        coluna * (LARGURA_CARTA + ESPACO_CORTE), // Determinar a coluna
        linha * (ALTURA_CARTA + ESPACO_CORTE),   // Determinar a linha
        LARGURA_CARTA,                           // Largura da carta
        ALTURA_CARTA                             // Altura da carta
    };

    // Desenhar a carta na posição desejada
    DrawTextureRec(textura, srcRec, posicao, WHITE);
}
