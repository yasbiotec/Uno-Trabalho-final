- Estrutura para as cartas (normais)
    Numero
    char Cor
- Estrutura para as cartas (especiais)
    carta (usa a estrutura carta normal)
    char "efeito" dela
  
- Estrutura mao do jogador:
    int contador de cartas
    cartas

- Lista baralho
  cartas
  cartas especiais


 - Estrutura jogadores 
     int ordem do turno (MAX 3 que seria o ultimo)
     Cartas que vieram do baralho


Função: 
- Baralho de cartas que usa o random para embararalhar as cartas de maneira aleatoria
    entrega para os jogadores suas cartas
    Tira do seu topo a primeira carta e a joga para começar

- Função Jogada-Valida
    Verifica se a carta que o jogador quer jogar é especial.
      Se sim, verifica se é +4
        Se não for, verifica se a cor da carta especial e se é da mesma que a carta do topo da mesa
          Se sim, deixa jogar
          Se não, mostra uma mensagem "jogada invalida" e retorna para deixar o jogador escolher novamente a carta
      Se for, deixa jogar
    Se não for, Verifica se a carta que o jogador quer jogar é da mesma cor que a primeira no topo ou se é o mesmo numero
      Se sim, deixa jogar.
    Se não, mostra uma mensagem "jogada invalida" e retorna para deixar o jogador escolher novamente a carta
   
     
    
