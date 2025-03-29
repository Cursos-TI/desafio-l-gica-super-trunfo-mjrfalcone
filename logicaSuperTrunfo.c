#include <stdio.h>
#include <string.h>

// Definição da estrutura Pais
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
    int densidade_demografica;
} Pais;

// Função para comparar as cartas com base nos atributos selecionados
int comparar(Pais carta1, Pais carta2, int atributo1, int atributo2) {
    int resultado = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 1) { // População
        resultado += (carta1.populacao > carta2.populacao) ? 1 : 0;
    } else if (atributo1 == 2) { // Área
        resultado += (carta1.area > carta2.area) ? 1 : 0;
    } else if (atributo1 == 3) { // PIB
        resultado += (carta1.pib > carta2.pib) ? 1 : 0;
    } else if (atributo1 == 4) { // Densidade Demográfica
        resultado += (carta1.densidade_demografica < carta2.densidade_demografica) ? 1 : 0;
    }

    // Comparação do segundo atributo
    if (atributo2 == 1) { // População
        resultado += (carta1.populacao > carta2.populacao) ? 1 : 0;
    } else if (atributo2 == 2) { // Área
        resultado += (carta1.area > carta2.area) ? 1 : 0;
    } else if (atributo2 == 3) { // PIB
        resultado += (carta1.pib > carta2.pib) ? 1 : 0;
    } else if (atributo2 == 4) { // Densidade Demográfica
        resultado += (carta1.densidade_demografica < carta2.densidade_demografica) ? 1 : 0;
    }

    return resultado;
}

// Função para exibir o resultado da comparação
void exibir_resultado(Pais carta1, Pais carta2, int atributo1, int atributo2) {
    int resultado = comparar(carta1, carta2, atributo1, atributo2);

    int soma1 = (atributo1 == 1 ? carta1.populacao : atributo1 == 2 ? carta1.area : atributo1 == 3 ? carta1.pib : carta1.densidade_demografica) +
                (atributo2 == 1 ? carta1.populacao : atributo2 == 2 ? carta1.area : atributo2 == 3 ? carta1.pib : carta1.densidade_demografica);

    int soma2 = (atributo1 == 1 ? carta2.populacao : atributo1 == 2 ? carta2.area : atributo1 == 3 ? carta2.pib : carta2.densidade_demografica) +
                (atributo2 == 1 ? carta2.populacao : atributo2 == 2 ? carta2.area : atributo2 == 3 ? carta2.pib : carta2.densidade_demografica);

    printf("\nResultado da comparação:\n");
    printf("Pais 1: %s\n", carta1.nome);
    printf("Pais 2: %s\n", carta2.nome);
    printf("Atributos comparados: %d e %d\n", atributo1, atributo2);
    printf("Soma dos Atributos Pais 1: %d\n", soma1);
    printf("Soma dos Atributos Pais 2: %d\n", soma2);

    if (soma1 > soma2) {
        printf("Pais %s venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Pais %s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }
}

// Função para escolher os atributos para comparação
void escolher_atributos(int *atributo1, int *atributo2) {
    int opcao;

    // Escolher primeiro atributo
    printf("Escolha o primeiro atributo (1. Populacao, 2. Area, 3. PIB, 4. Densidade Demografica): ");
    scanf("%d", &opcao);
    *atributo1 = opcao;

    // Escolher segundo atributo (não pode ser o mesmo)
    do {
        printf("Escolha o segundo atributo (1. Populacao, 2. Area, 3. PIB, 4. Densidade Demografica): ");
        scanf("%d", &opcao);
    } while (opcao == *atributo1);

    *atributo2 = opcao;
}

// Função principal
int main() {
    // Definindo as cartas (paises)
    Pais paises[2] = {
        {"Brasil", 211000000, 8515767, 2200000, 24},
        {"Argentina", 45195777, 2780400, 600000, 16}
    };

    // Escolher os atributos para comparação
    int atributo1, atributo2;
    escolher_atributos(&atributo1, &atributo2);

    // Exibir resultado da comparação
    exibir_resultado(paises[0], paises[1], atributo1, atributo2);

    return 0;
}
