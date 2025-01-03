#ifndef _TADS_
#define _TADS_

#define TAM_NOME 40
#define TAM_EMAIL 25

// Definindo as cores de cartas como um enum
typedef enum {
    AMARELO = 0,
    VERDE,
    VERMELHO,
    AZUL,
    PRETA,
} CorCarta;

typedef struct {
    int num;
    CorCarta cor;
} Info;

typedef struct nodoLEnc2 {
    Info info;
    struct nodoLEnc2* prox;
    struct nodoLEnc2* ant;
} Carta;

typedef struct Mao {
    int n_cartas;
    struct nodoLEnc2* prim;
} Mao;

////////////////////////////////////////////////////////

typedef struct nodoLEnc {
    int pontos;
    char nome[20];
    struct Mao* mao;
    struct nodoLEnc* prox;
    struct nodoLEnc* ant;
} Jogador;

typedef struct {
    Jogador* prim;
} ListaJogadores;

//////////////////////////////////////////////////////////

typedef struct pilhaEnc {
    struct nodoPEnc* topo;
} PilhaCartas;

typedef struct nodoPEnc {
    Info info;
    struct nodoPEnc* prox;
} CartaPilha;

// Funções para manipulação de cartas e jogadores
Mao* criaMao();
int insereInicioMao(Mao* mao, Info info);
Info removeCartaMao(Mao* mao, Carta* carta);
PilhaCartas* criaPilhaCartas();
void empilhaPilhaCartas(PilhaCartas* pilha, Info info);
Info desempilhaPilhaCartas(PilhaCartas* pilha);

#endif
