/*****************************************************************//**
 * \file   OperacoesMatriz.c
 * \brief  Biblioteca com funções que fazem cálculos e operações com a matriz
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
/// Função para obter o endereço de um elemento dado as coordenadas
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="linha">Linha do elemento</param>
/// <param name="coluna">Coluna do elemento</param>
/// <returns>Endereço do elemento</returns>
Elemento* ObterElemento(Matriz* matriz, int linha, int coluna) {
    //Se a matriz é nula
    if (matriz == NULL) {
        printf("Endereço da matriz inválido.\n");
        return NULL;
    } 
    //Verifica se as coordenadas dadas não passam do limite da matriz
    if (matriz->colunas <= coluna || matriz->linhas <= linha) { 
        printf("Limite de linhas ou colunas excedido ou um dos valores, verifique se deu a coordenada correta.\n");
        return NULL;
    }
    Elemento* aux = matriz->inicio;
    //Percorre a matriz por linhas
    for (int i = 0; i < linha; i++) {
        aux = aux->proxlinha;
    }
    //Percorre as colunas da linha
    for (int i = 0; i < coluna; i++) {
        aux = aux->prox;
    }
    return aux;
}

int SomaMaximaPossivel(Matriz* matriz){
    //Se a matriz é nula
    if (matriz == NULL) {
        printf("Endereço da matriz inválido.\n");
        return NULL;
    }

}
