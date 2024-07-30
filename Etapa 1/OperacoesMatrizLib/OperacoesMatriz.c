/*****************************************************************//**
 * \file   OperacoesMatriz.c
 * \brief  Biblioteca com fun��es que fazem c�lculos e opera��es com a matriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma warning (disable: 4996)

#include "DadosFixos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// <summary>
/// Fun��o para obter o endere�o de um elemento dado as coordenadas
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="linha">Linha do elemento</param>
/// <param name="coluna">Coluna do elemento</param>
/// <returns>Endere�o do elemento</returns>
Elemento* ObterElemento(Matriz* matriz, int linha, int coluna) {
    // Se a matriz � nula
    if (matriz == NULL) {
        printf("Endere�o da matriz inv�lido.\n");
        return NULL;
    }

    // Verifica se as coordenadas dadas n�o passam do limite da matriz
    if (matriz->colunas <= coluna || matriz->linhas <= linha) { 
        printf("Limite de linhas ou colunas excedido ou um dos valores, verifique se deu a coordenada correta.\n");
        return NULL;
    }

    Elemento* aux = matriz->inicio;
    // Percorre a matriz por linhas
    for (int i = 0; i < linha; i++) {
        aux = aux->proxlinha;
    }
    // Percorre as colunas da linha
    for (int i = 0; i < coluna; i++) {
        aux = aux->prox;
    }

    return aux;
}

/// <summary>
/// Fun��o para preencher uma arra bidimensional com os inteiros da matriz
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <returns>Endere�o do primeiro elemento da array bidimensional</returns>
int** MatrizParaArrayBidimensional(Matriz* matriz) {
    // Se a matriz � nula
    if (matriz == NULL) {
        printf("Endere�o da matriz inv�lido.\n");
        return NULL;
    }

    int linhas = matriz->linhas;
    int colunas = matriz->colunas;
    
    // Aloca mem�ria para o array bidimensional
    int** array = (int**)malloc(linhas * sizeof(int*));
    if (array == NULL) {
        printf("Erro ao alocar mem�ria para o array bidimensional.\n");
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        array[i] = (int*)malloc(colunas * sizeof(int));
        if (array[i] == NULL) {
            printf("Erro ao alocar mem�ria para a linha %d do array bidimensional.\n", i);
            // Liberar mem�ria j� alocada
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }

    // Preenche o array bidimensional com os valores da matriz
    Elemento* elemento = matriz->inicio;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            array[i][j] = elemento->inteiro;
            elemento = elemento->prox;
        }
        if (elemento == NULL) break;
    }

    return array;
}

/// <summary>
/// Fun��o auxiliar para calcular a soma m�xima de forma recursiva
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="biMatriz">Endere�o do array bidimensional</param>
/// <param name="linha_atual">Linha atual</param>
/// <param name="colunas_usadas">Colunas usadas para evitar o uso de colunas inv�lidas</param>
/// <returns>Soma m�xima poss�vel</returns>
int CalcularSomaMaximaRecursiva(Matriz* matriz, int** biMatriz, int linha_atual, int* colunas_usadas) {
    // Se chegarmos ao final da matriz, retornamos 0
    if (linha_atual >= matriz->linhas)
        return 0;

    // Inicializamos a soma m�xima para a linha atual como 0
    int max_soma_linha_atual = 0;

    // Percorremos todas as colunas da linha atual
    for (int coluna = 0; coluna < matriz->colunas; coluna++) {
        // Verificamos se a coluna j� foi usada
        if (!colunas_usadas[coluna]) {
            // Calculamos a soma para a linha atual e marcamos a coluna como usada
            colunas_usadas[coluna] = 1;
            int soma_atual = biMatriz[linha_atual][coluna];

            // Chamamos a fun��o recursivamente para a pr�xima linha
            int soma_proxima_linha = CalcularSomaMaximaRecursiva(matriz, biMatriz, linha_atual + 1, colunas_usadas);

            // Atualizamos a soma m�xima para a linha atual
            max_soma_linha_atual = (soma_atual + soma_proxima_linha > max_soma_linha_atual) ? soma_atual + soma_proxima_linha : max_soma_linha_atual;

            // Desmarcamos a coluna ap�s a chamada recursiva
            colunas_usadas[coluna] = 0;
        }
    }

    return max_soma_linha_atual;
}

/// <summary>
/// Fun��o principal para calcular a soma m�xima de forma inteligente
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <returns>Soma m�xima poss�vel da matriz</returns>
int CalcularSomaMaxima(Matriz* matriz) {
    int** arrayMatriz = MatrizParaArrayBidimensional(matriz);

    // Inicializamos o array de colunas usadas como falso para todas as colunas
    int colunas = matriz->colunas;
    int* colunas_usadas = (int*)calloc(colunas, sizeof(int));

    // Chamamos a fun��o recursiva para calcular a soma m�xima
    int soma_maxima = CalcularSomaMaximaRecursiva(matriz, arrayMatriz, 0, colunas_usadas);

    // Liberamos a mem�ria alocada para o array bidimensional e o array de colunas usadas
    for (int i = 0; i < matriz->linhas; i++) {
        free(arrayMatriz[i]);
    }
    free(arrayMatriz);
    free(colunas_usadas);

    return soma_maxima;
}
