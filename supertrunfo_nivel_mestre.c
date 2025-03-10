#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados das cartas
typedef struct {
    char estado;
    char codigo[5];
    char cidade[50];
    unsigned long int populacao;
    float area, pib;
    int pontos;
    float densidade, pibPerCapita;
} Carta;

int main() {
    Carta carta1 = {'A', "A01", "Cidade Alpha", 500000, 600.5, 20.5, 15, 0, 0};
    Carta carta2 = {'B', "B02", "Cidade Beta", 300000, 400.3, 15.2, 10, 0, 0};
    
    // Cálculo da densidade demográfica e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;
    
    int escolha1, escolha2;
    float valor1_1, valor1_2, valor2_1, valor2_2;
    
    // Exibição do menu de escolha do primeiro atributo
    printf("Escolha o primeiro atributo para comparacao:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n6 - PIB per Capita\n");
    scanf("%d", &escolha1);
    
    // Exibição do menu de escolha do segundo atributo (sem repetir o primeiro)
    printf("Escolha o segundo atributo para comparacao (diferente do primeiro):\n");
    scanf("%d", &escolha2);
    
    // Comparação dos atributos escolhidos
    switch (escolha1) {
        case 1: valor1_1 = carta1.populacao; valor2_1 = carta2.populacao; break;
        case 2: valor1_1 = carta1.area; valor2_1 = carta2.area; break;
        case 3: valor1_1 = carta1.pib; valor2_1 = carta2.pib; break;
        case 4: valor1_1 = carta1.pontos; valor2_1 = carta2.pontos; break;
        case 5: valor1_1 = carta1.densidade; valor2_1 = carta2.densidade; break;
        case 6: valor1_1 = carta1.pibPerCapita; valor2_1 = carta2.pibPerCapita; break;
        default: printf("Atributo invalido.\n"); return 1;
    }
    
    switch (escolha2) {
        case 1: valor1_2 = carta1.populacao; valor2_2 = carta2.populacao; break;
        case 2: valor1_2 = carta1.area; valor2_2 = carta2.area; break;
        case 3: valor1_2 = carta1.pib; valor2_2 = carta2.pib; break;
        case 4: valor1_2 = carta1.pontos; valor2_2 = carta2.pontos; break;
        case 5: valor1_2 = carta1.densidade; valor2_2 = carta2.densidade; break;
        case 6: valor1_2 = carta1.pibPerCapita; valor2_2 = carta2.pibPerCapita; break;
        default: printf("Atributo invalido.\n"); return 1;
    }
    
    // Cálculo da pontuação final
    float soma1 = valor1_1 + valor1_2;
    float soma2 = valor2_1 + valor2_2;
    
    // Exibição do resultado
    printf("\nComparacao de cartas:\n");
    printf("%s (%c): %.2f + %.2f = %.2f\n", carta1.cidade, carta1.estado, valor1_1, valor1_2, soma1);
    printf("%s (%c): %.2f + %.2f = %.2f\n", carta2.cidade, carta2.estado, valor2_1, valor2_2, soma2);
    
    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", carta1.cidade);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", carta2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    return 0;
}