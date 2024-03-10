/*****************************************************************//**
 * \file   ManipulacaoMatriz.c
 * \brief  
 * 
 * \author mtcig
 * \date   March 2024
 *********************************************************************/

#pragma warning (disable: 4996)

#include "DadosFixos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// <summary>
/// Função para libertar a memória usada para a matriz
/// </summary>
/// <param name="inicio">Endereço do início da matriz</param>
void LibertarMemoria(Matriz* matriz) {
    Elemento* aux = matriz->inicio;
    free(matriz);
    while (aux->prox != NULL) {
        Elemento* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(aux);
}

/// <summary>
/// Função para reservar espaço na memória para um elemento já atribúido um número inteiro
/// </summary>
/// <param name="inteiro">Número inteiro para o elemento da matriz</param>
/// <returns>Endereço do elemento na memória</returns>
Elemento* CriarElemento(int inteiro) {
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento));
    if (aux == NULL) return NULL;
    aux->inteiro = inteiro;
    aux->prox = NULL;
    aux->proxlinha = NULL;
    return aux;
}

/// <summary>
/// Inicializa a estrutura com dados da matriz como linhas e colunas e também o primeiro elemento da matriz
/// </summary>
/// <param name="linhas">Número de linhas da matriz</param>
/// <param name="colunas">Número de colunas da matriz</param>
/// <param name="inicio">Endereço do primeiro elemento da matriz</param>
/// <returns>Endereço dos dados da matriz</returns>
Matriz* AtribuirMatriz(int linhas, int colunas, Elemento* inicio) {
    Matriz* aux = (Matriz*)malloc(sizeof(Matriz));
    if (aux == NULL) return NULL;
    aux->linhas = linhas;
    aux->colunas = colunas;
    aux->inicio = inicio;
    return aux;
}

/// <summary>
/// Função para inserir o elemento novo á matriz
/// </summary>
/// <param name="inicio">Início da matriz</param>
/// <param name="nova">Novo elemento para inserir</param>
/// <param name="novaLinha">Váriavel de controlo se o elemento é de uma nova linha</param>
/// <returns>Início da matriz</returns>
Elemento* InserirElemento(Elemento* inicio, Elemento* nova, bool novaLinha) {
    if (nova == NULL) return inicio;
    if (inicio == NULL) inicio = nova;
    else {
        Elemento* aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
        if (novaLinha == true) {
            Elemento* aux2 = inicio;
            while (aux2->proxlinha != NULL) {
                aux2 = aux2->proxlinha;
            }
            aux2->proxlinha = aux->prox;
        }
    }
    return inicio;
}

void RemoverLinha(Matriz* matriz, int linha) {
    // Verificação de parâmetros
    if (matriz == NULL || linha < 0 || linha >= matriz->linhas) {
        return;
    }

    // Ponteiro para o início da linha a remover
    Elemento* linhaToRemove = matriz->inicio;
    for (int i = 0; i < linha; i++) {
        linhaToRemove = linhaToRemove->proxlinha;
    }

    // Ponteiro para o elemento anterior à linha a remover
    Elemento* anterior = NULL;
    Elemento* atual = matriz->inicio;
    while (atual != linhaToRemove) {
        anterior = atual;
        atual = atual->proxlinha;
    }

    // Se a linha a remover for a primeira
    if (anterior == NULL) {
        matriz->inicio = linhaToRemove->proxlinha;
    }
    else {
        anterior->proxlinha = linhaToRemove->proxlinha;
    }

    // Liberar memória da linha removida
    Elemento* aux = linhaToRemove;
    while (aux != NULL) {
        Elemento* temp = aux;
        aux = aux->prox;
        free(temp);
    }

    // Atualizar o número de linhas da matriz
    matriz->linhas--;
}