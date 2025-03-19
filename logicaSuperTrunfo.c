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
    
    float dens1 = (float)pop1 / area1, dens2 = (float)pop2 / area2;
    float pibcap1 = pib1 / pop1, pibcap2 = pib2 / pop2;
    float super_poder1 = pop1 + area1 + pib1 + tur1 + pibcap1 + (1.0 / dens1);
    float super_poder2 = pop2 + area2 + pib2 + tur2 + pibcap2 + (1.0 / dens2);
    
    printf("\nResultados:\n");
    printf("1 CARTA:\n");
    printf("Estado: %s", esta1);
    printf("Código: %s", cod1);
    printf("Cidade: %s", cidade1);
    printf("População: %lu\n", pop1);
    printf("Área: %.1f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos turísticos: %d\n", tur1);
    printf("Densidade Populacional: %.2f\n", dens1);
    printf("PIB per Capita: %.2f\n", pibcap1);
    printf("Super Poder: %.2f\n", super_poder1);
    
    printf("\n2 CARTA:\n");
    printf("Estado: %s", esta2);
    printf("Código: %s", cod2);
    printf("Cidade: %s", cidade2);
    printf("População: %lu\n", pop2);
    printf("Área: %.1f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos turísticos: %d\n", tur2);
    printf("Densidade Populacional: %.2f\n", dens2);
    printf("PIB per Capita: %.2f\n", pibcap2);
    printf("Super Poder: %.2f\n", super_poder2);
    
    printf("\nComparação das Cartas:\n");

    if (pop1 > pop2) {
        printf("População: %s vence!\n", cidade1);
    } else if (pop1 < pop2) {
        printf("População: %s vence!\n", cidade2);
    } else {
        printf("População: Empate!\n");
    }

    if (area1 > area2) {
        printf("Área: %s vence!\n", cidade1);
    } else if (area1 < area2) {
        printf("Área: %s vence!\n", cidade2);
    } else {
        printf("Área: Empate!\n");
    }

    if (pib1 > pib2) {
        printf("PIB: %s vence!\n", cidade1);
    } else if (pib1 < pib2) {
        printf("PIB: %s vence!\n", cidade2);
    } else {
        printf("PIB: Empate!\n");
    }

    if (tur1 > tur2) {
        printf("Pontos Turísticos: %s vence!\n", cidade1);
    } else if (tur1 < tur2) {
        printf("Pontos Turísticos: %s vence!\n", cidade2);
    } else {
        printf("Pontos Turísticos: Empate!\n");
    }

    if (dens1 < dens2) {
        printf("Densidade Populacional: %s vence!\n", cidade1);
    } else if (dens1 > dens2) {
        printf("Densidade Populacional: %s vence!\n", cidade2);
    } else {
        printf("Densidade Populacional: Empate!\n");
    }

    if (pibcap1 > pibcap2) {
        printf("PIB per Capita: %s vence!\n", cidade1);
    } else if (pibcap1 < pibcap2) {
        printf("PIB per Capita: %s vence!\n", cidade2);
    } else {
        printf("PIB per Capita: Empate!\n");
    }

    if (super_poder1 > super_poder2) {
        printf("Super Poder: %s vence!\n", cidade1);
    } else if (super_poder1 < super_poder2) {
        printf("Super Poder: %s vence!\n", cidade2);
    } else {
        printf("Super Poder: Empate!\n");
    }

    return 0;
}
