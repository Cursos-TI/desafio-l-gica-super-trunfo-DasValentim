#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char esta1[20], esta2[20];
    char cidade1[20], cidade2[20], cod1[5], cod2[5];
    unsigned long int pop1, pop2;
    int tur1, tur2;
    float area1, area2, pib1, pib2;

    printf("CADASTRO DE CARTAS!\n");
    printf("\nCARTA 1:\n");
    printf("Escreva o nome do estado:\n");
    fgets(esta1, 20, stdin);
    printf("Escreva o código da carta:\n");
    fgets(cod1, 5, stdin);
    printf("Escreva o nome da cidade:\n");
    fgets(cidade1, 20, stdin);
    printf("Escreva a população da cidade:\n");
    scanf("%lu", &pop1);
    printf("Escreva a área da cidade:\n");
    scanf("%f", &area1);
    printf("Escreva o PIB da cidade:\n");
    scanf("%f", &pib1);
    printf("Escreva a quantidade de pontos turísticos da cidade:\n");
    scanf("%d", &tur1);
    getchar();

    printf("\nCARTA 2:\n");
    printf("Escreva o nome do estado:\n");
    fgets(esta2, 20, stdin);
    printf("Escreva o código da carta:\n");
    fgets(cod2, 5, stdin);
    printf("Escreva o nome da cidade:\n");
    fgets(cidade2, 20, stdin);
    printf("Escreva a população da cidade:\n");
    scanf("%lu", &pop2);
    printf("Escreva a área da cidade:\n");
    scanf("%f", &area2);
    printf("Escreva o PIB da cidade:\n");
    scanf("%f", &pib2);
    printf("Escreva a quantidade de pontos turísticos da cidade:\n");
    scanf("%d", &tur2);
    getchar();

    float dens1 = (float)pop1 / area1, dens2 = (float)pop2 / area2;
    float pibcap1 = pib1 / pop1, pibcap2 = pib2 / pop2;
    float super_poder1 = pop1 + area1 + pib1 + tur1 + pibcap1 + (1.0 / dens1);
    float super_poder2 = pop2 + area2 + pib2 + tur2 + pibcap2 + (1.0 / dens2);

    int opcao;
    do {
        printf("\nMENU DE COMPARAÇÃO:\n");
        printf("1. Comparar População\n");
        printf("2. Comparar Área\n");
        printf("3. Comparar PIB\n");
        printf("4. Comparar Pontos Turísticos\n");
        printf("5. Comparar Densidade Populacional\n");
        printf("6. Comparar PIB per Capita\n");
        printf("7. Comparar Super Poder\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (pop1 > pop2) {
                    printf("População: %s vence!\n", cidade1);
                } else if (pop1 < pop2) {
                    printf("População: %s vence!\n", cidade2);
                } else {
                    printf("População: Empate!\n");
                }
                break;

            case 2:
                if (area1 > area2) {
                    printf("Área: %s vence!\n", cidade1);
                } else if (area1 < area2) {
                    printf("Área: %s vence!\n", cidade2);
                } else {
                    printf("Área: Empate!\n");
                }
                break;

            case 3:
                if (pib1 > pib2) {
                    printf("PIB: %s vence!\n", cidade1);
                } else if (pib1 < pib2) {
                    printf("PIB: %s vence!\n", cidade2);
                } else {
                    printf("PIB: Empate!\n");
                }
                break;

            case 4:
                if (tur1 > tur2) {
                    printf("Pontos Turísticos: %s vence!\n", cidade1);
                } else if (tur1 < tur2) {
                    printf("Pontos Turísticos: %s vence!\n", cidade2);
                } else {
                    printf("Pontos Turísticos: Empate!\n");
                }
                break;

            case 5:
                if (dens1 < dens2) {
                    printf("Densidade Populacional: %s vence!\n", cidade1);
                } else if (dens1 > dens2) {
                    printf("Densidade Populacional: %s vence!\n", cidade2);
                } else {
                    printf("Densidade Populacional: Empate!\n");
                }
                break;

            case 6:
                if (pibcap1 > pibcap2) {
                    printf("PIB per Capita: %s vence!\n", cidade1);
                } else if (pibcap1 < pibcap2) {
                    printf("PIB per Capita: %s vence!\n", cidade2);
                } else {
                    printf("PIB per Capita: Empate!\n");
                }
                break;

            case 7:
                if (super_poder1 > super_poder2) {
                    printf("Super Poder: %s vence!\n", cidade1);
                } else if (super_poder1 < super_poder2) {
                    printf("Super Poder: %s vence!\n", cidade2);
                } else {
                    printf("Super Poder: Empate!\n");
                }
                break;

            case 8:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}
