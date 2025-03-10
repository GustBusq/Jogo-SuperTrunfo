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
    Carta carta1, carta2;

    // Entrada de dados para a primeira carta
    printf("Digite as informacoes da primeira carta:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &carta1.estado);
    printf("Codigo da carta (A01, B03...): ");
    scanf("%s", carta1.codigo);
    
    printf("Nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
    carta1.cidade[strcspn(carta1.cidade, "\n")] = '\0';
    
    printf("Populacao da cidade: ");
    scanf("%lu", &carta1.populacao);
    printf("Area da cidade em km²: ");
    scanf("%f", &carta1.area);
    printf("PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontos);

    // Entrada de dados para a segunda carta
    printf("\nDigite as informacoes da segunda carta:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da carta (A01, B03...): ");
    scanf("%s", carta2.codigo);
    
    printf("Nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = '\0';
    
    printf("Populacao da cidade: ");
    scanf("%lu", &carta2.populacao);
    printf("Area da cidade em km²: ");
    scanf("%f", &carta2.area);
    printf("PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontos);

    // Cálculos
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação
    char atributoEscolhido[] = "PIB"; // Modifique aqui o atributo desejado
    int vencedor;
    float valor1, valor2;
    
    if (strcmp(atributoEscolhido, "Populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
        vencedor = (valor1 > valor2) ? 1 : 2;
    } else if (strcmp(atributoEscolhido, "Area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
        vencedor = (valor1 > valor2) ? 1 : 2;
    } else if (strcmp(atributoEscolhido, "PIB") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
        vencedor = (valor1 > valor2) ? 1 : 2;
    } else if (strcmp(atributoEscolhido, "Densidade Populacional") == 0) {
        valor1 = carta1.densidade;
        valor2 = carta2.densidade;
        vencedor = (valor1 < valor2) ? 1 : 2; // Menor valor vence
    } else if (strcmp(atributoEscolhido, "PIB per Capita") == 0) {
        valor1 = carta1.pibPerCapita;
        valor2 = carta2.pibPerCapita;
        vencedor = (valor1 > valor2) ? 1 : 2;
    } else {
        printf("Atributo invalido.\n");
        return 1;
    }

    // Exibição do resultado
    printf("\nComparacao de cartas (Atributo: %s):\n", atributoEscolhido);
    printf("Carta 1 - %s (%c): %.2f\n", carta1.cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%c): %.2f\n", carta2.cidade, carta2.estado, valor2);
    printf("Resultado: Carta %d (%s) venceu!\n", vencedor, (vencedor == 1) ? carta1.cidade : carta2.cidade);

    return 0;
}