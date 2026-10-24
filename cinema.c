#include <stdio.h>

#define M 5 // quantidade de filmes em cartaz no mes

int main() {
    char filmes[M][30];  // nome de cada filme
    int ingressos[M];    // ingressos vendidos por filme no mes
    int i, j;
    int total = 0;
    int maior = 0, menor = 0;

    printf("=== Vendas de cinema do mes ===\n\n");

    // le o nome e os ingressos de cada filme
    for (i = 0; i < M; i++) {
        printf("Nome do filme %d: ", i + 1);
        scanf(" %29[^\n]", filmes[i]);
        printf("Ingressos vendidos: ");
        scanf("%d", &ingressos[i]);

        total = total + ingressos[i];

        // guarda a posicao do mais e do menos assistido
        if (ingressos[i] > ingressos[maior]) {
            maior = i;
        }
        if (ingressos[i] < ingressos[menor]) {
            menor = i;
        }
    }

    // mostra o resultado
    printf("\n=== Resultado ===\n");
    for (i = 0; i < M; i++) {
        printf("%-30s %5d ingressos\n", filmes[i], ingressos[i]);
    }
    printf("\nTotal de ingressos: %d\n", total);
    printf("Media por filme: %.1f\n", (float) total / M);
    printf("Mais assistido: %s (%d)\n", filmes[maior], ingressos[maior]);
    printf("Menos assistido: %s (%d)\n", filmes[menor], ingressos[menor]);

    // bonus: grafico de barras, cada * vale 10 ingressos
    printf("\n=== Grafico (cada * = 10 ingressos) ===\n");
    for (i = 0; i < M; i++) {
        printf("%-30s ", filmes[i]);
        for (j = 0; j < ingressos[i] / 10; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
