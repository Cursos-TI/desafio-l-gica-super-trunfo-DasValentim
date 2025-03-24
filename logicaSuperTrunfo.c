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

    int opcao, atributo1, atributo2;
    do {
        printf("\nMENU DE COMPARAÇÃO:\n");
        printf("1. Comparar um atributo\n");
        printf("2. Comparar dois atributos simultaneamente\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                printf("\nATRIBUTOS DISPONÍVEIS:\n");
                printf("1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turísticos\n");
                printf("5. Densidade Populacional\n");
                printf("6. PIB per Capita\n");
                printf("7. Super Poder\n");
                printf("Escolha o atributo: ");
                scanf("%d", &atributo1);
                getchar();

                char *vencedor;
                float valor1, valor2;
                char *nomeAtributo;
                
                switch(atributo1) {
                    case 1: 
                        valor1 = pop1; valor2 = pop2; nomeAtributo = "População";
                        vencedor = (pop1 > pop2) ? cidade1 : (pop1 < pop2) ? cidade2 : "Empate";
                        break;
                    case 2:
                        valor1 = area1; valor2 = area2; nomeAtributo = "Área";
                        vencedor = (area1 > area2) ? cidade1 : (area1 < area2) ? cidade2 : "Empate";
                        break;
                    case 3:
                        valor1 = pib1; valor2 = pib2; nomeAtributo = "PIB";
                        vencedor = (pib1 > pib2) ? cidade1 : (pib1 < pib2) ? cidade2 : "Empate";
                        break;
                    case 4:
                        valor1 = tur1; valor2 = tur2; nomeAtributo = "Pontos Turísticos";
                        vencedor = (tur1 > tur2) ? cidade1 : (tur1 < tur2) ? cidade2 : "Empate";
                        break;
                    case 5:
                        valor1 = dens1; valor2 = dens2; nomeAtributo = "Densidade Populacional";
                        vencedor = (dens1 < dens2) ? cidade1 : (dens1 > dens2) ? cidade2 : "Empate";
                        break;
                    case 6:
                        valor1 = pibcap1; valor2 = pibcap2; nomeAtributo = "PIB per Capita";
                        vencedor = (pibcap1 > pibcap2) ? cidade1 : (pibcap1 < pibcap2) ? cidade2 : "Empate";
                        break;
                    case 7:
                        valor1 = super_poder1; valor2 = super_poder2; nomeAtributo = "Super Poder";
                        vencedor = (super_poder1 > super_poder2) ? cidade1 : (super_poder1 < super_poder2) ? cidade2 : "Empate";
                        break;
                    default:
                        printf("Atributo inválido!\n");
                        continue;
                }

                printf("\n--- RESULTADO ---\n");
                printf("%s: %s = %.2f\n", nomeAtributo, cidade1, valor1);
                printf("%s: %s = %.2f\n", nomeAtributo, cidade2, valor2);
                printf("\nVencedor: %s\n", vencedor);
                if(strcmp(vencedor, "Empate") == 0) {
                    printf("As cidades têm o mesmo valor para este atributo!\n");
                }
                break;
            }

            case 2: {
                printf("\nESCOLHA DOIS ATRIBUTOS PARA COMPARAR:\n");
                printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n");
                printf("5. Densidade Populacional\n6. PIB per Capita\n7. Super Poder\n");
                
                printf("Primeiro atributo: ");
                scanf("%d", &atributo1);
                getchar();
                printf("Segundo atributo: ");
                scanf("%d", &atributo2);
                getchar();

                float valores1[2], valores2[2];
                char *nomesAtributos[2];
                char *vencedores[2];

                switch(atributo1) {
                    case 1: 
                        valores1[0] = pop1; valores2[0] = pop2; 
                        nomesAtributos[0] = "População";
                        vencedores[0] = (pop1 > pop2) ? cidade1 : (pop1 < pop2) ? cidade2 : "Empate";
                        break;
                    case 2:
                        valores1[0] = area1; valores2[0] = area2; 
                        nomesAtributos[0] = "Área";
                        vencedores[0] = (area1 > area2) ? cidade1 : (area1 < area2) ? cidade2 : "Empate";
                        break;
                    case 3:
                        valores1[0] = pib1; valores2[0] = pib2; 
                        nomesAtributos[0] = "PIB";
                        vencedores[0] = (pib1 > pib2) ? cidade1 : (pib1 < pib2) ? cidade2 : "Empate";
                        break;
                    case 4:
                        valores1[0] = tur1; valores2[0] = tur2; 
                        nomesAtributos[0] = "Pontos Turísticos";
                        vencedores[0] = (tur1 > tur2) ? cidade1 : (tur1 < tur2) ? cidade2 : "Empate";
                        break;
                    case 5:
                        valores1[0] = dens1; valores2[0] = dens2; 
                        nomesAtributos[0] = "Densidade Populacional";
                        vencedores[0] = (dens1 < dens2) ? cidade1 : (dens1 > dens2) ? cidade2 : "Empate";
                        break;
                    case 6:
                        valores1[0] = pibcap1; valores2[0] = pibcap2; 
                        nomesAtributos[0] = "PIB per Capita";
                        vencedores[0] = (pibcap1 > pibcap2) ? cidade1 : (pibcap1 < pibcap2) ? cidade2 : "Empate";
                        break;
                    case 7:
                        valores1[0] = super_poder1; valores2[0] = super_poder2; 
                        nomesAtributos[0] = "Super Poder";
                        vencedores[0] = (super_poder1 > super_poder2) ? cidade1 : (super_poder1 < super_poder2) ? cidade2 : "Empate";
                        break;
                    default:
                        printf("Primeiro atributo inválido!\n");
                        continue;
                }

                switch(atributo2) {
                    case 1: 
                        valores1[1] = pop1; valores2[1] = pop2; 
                        nomesAtributos[1] = "População";
                        vencedores[1] = (pop1 > pop2) ? cidade1 : (pop1 < pop2) ? cidade2 : "Empate";
                        break;
                    case 2:
                        valores1[1] = area1; valores2[1] = area2; 
                        nomesAtributos[1] = "Área";
                        vencedores[1] = (area1 > area2) ? cidade1 : (area1 < area2) ? cidade2 : "Empate";
                        break;
                    case 3:
                        valores1[1] = pib1; valores2[1] = pib2; 
                        nomesAtributos[1] = "PIB";
                        vencedores[1] = (pib1 > pib2) ? cidade1 : (pib1 < pib2) ? cidade2 : "Empate";
                        break;
                    case 4:
                        valores1[1] = tur1; valores2[1] = tur2; 
                        nomesAtributos[1] = "Pontos Turísticos";
                        vencedores[1] = (tur1 > tur2) ? cidade1 : (tur1 < tur2) ? cidade2 : "Empate";
                        break;
                    case 5:
                        valores1[1] = dens1; valores2[1] = dens2; 
                        nomesAtributos[1] = "Densidade Populacional";
                        vencedores[1] = (dens1 < dens2) ? cidade1 : (dens1 > dens2) ? cidade2 : "Empate";
                        break;
                    case 6:
                        valores1[1] = pibcap1; valores2[1] = pibcap2; 
                        nomesAtributos[1] = "PIB per Capita";
                        vencedores[1] = (pibcap1 > pibcap2) ? cidade1 : (pibcap1 < pibcap2) ? cidade2 : "Empate";
                        break;
                    case 7:
                        valores1[1] = super_poder1; valores2[1] = super_poder2; 
                        nomesAtributos[1] = "Super Poder";
                        vencedores[1] = (super_poder1 > super_poder2) ? cidade1 : (super_poder1 < super_poder2) ? cidade2 : "Empate";
                        break;
                    default:
                        printf("Segundo atributo inválido!\n");
                        continue;
                }

                printf("\n--- RESULTADOS COMPARADOS ---\n");
                for(int i = 0; i < 2; i++) {
                    printf("%s:\n", nomesAtributos[i]);
                    printf("- %s: %.2f\n", cidade1, valores1[i]);
                    printf("- %s: %.2f\n", cidade2, valores2[i]);
                    printf("Vencedor: %s\n\n", vencedores[i]);
                }

                if(strcmp(vencedores[0], vencedores[1]) == 0) {
                    printf("RESULTADO FINAL: %s vence em ambos os critérios!\n", vencedores[0]);
                } else if(strcmp(vencedores[0], "Empate") == 0 && strcmp(vencedores[1], "Empate") == 0) {
                    printf("RESULTADO FINAL: Empate em ambos os critérios!\n");
                } else {
                    printf("RESULTADO FINAL: Cada cidade venceu em um critério diferente!\n");
                }
                break;
            }

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
