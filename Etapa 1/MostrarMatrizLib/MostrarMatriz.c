/*****************************************************************//**
 * \file   MostrarMatriz.c
 * \brief  Fun��es para mostrar o output na consola
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma warning (disable: 4996)

#include "DadosFixos.h"
#include "OperacoesMatriz.h"
#include <stdio.h>

/// <summary>
/// Fun��o para mostrar na consola em forma de tabela a matriz
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
void ListagemTabular(Matriz* matriz) {
    if (matriz == NULL) {
        printf("Matriz inv�lida.\n");
        return;
    }

    // Linha superior da tabela
    printf("+");
    for (int c = 0; c < matriz->colunas; c++) {
        printf("-----+");
    }
    printf("\n");

    // Conte�do da matriz
    for (int l = 0; l < matriz->linhas; l++) {
        printf("|");
        for (int c = 0; c < matriz->colunas; c++) {
            Elemento* elemento = ObterElemento(matriz, l, c);
            printf("% 3d |", elemento->inteiro);
        }
        printf("\n");
        // Linha separadora entre as linhas da matriz
        printf("+");
        for (int c = 0; c < matriz->colunas; c++) {
            printf("-----+");
        }
        printf("\n");
    }
}

