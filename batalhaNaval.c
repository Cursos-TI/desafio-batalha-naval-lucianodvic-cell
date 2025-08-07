#include <stdio.h>

#define TAM 10        // Tamanho fixo do tabuleiro 10x10
#define NAVIO 3       // Valor que representa uma parte do navio no tabuleiro
#define AGUA 0        // Valor que representa água
#define TAM_NAVIO 3   // Comprimento fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Coordenadas iniciais dos navios (linha, coluna)
    // Navio horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Navio vertical
    int linhaV = 6;
    int colunaV = 7;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona navio horizontal (3 posições)
    // Validação: não ultrapassar o limite do tabuleiro
    if (colunaH + TAM_NAVIO <= TAM) {
        for (j = colunaH; j < colunaH + TAM_NAVIO; j++) {
            tabuleiro[linhaH][j] = NAVIO;
        }
    }

    // Posiciona navio vertical (3 posições)
    // Validação: não ultrapassar o limite do tabuleiro
    // e não sobrepor navio horizontal
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;
        for (i = linhaV; i < linhaV + TAM_NAVIO; i++) {
            if (tabuleiro[i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (i = linhaV; i < linhaV + TAM_NAVIO; i++) {
                tabuleiro[i][colunaV] = NAVIO;
            }
        } else {
            printf("Erro: navios sobrepostos! Ajuste as coordenadas.\n");
            return 1;
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio)\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
