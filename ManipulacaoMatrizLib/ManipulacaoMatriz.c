/*****************************************************************//**
 * \file   ManipulacaoMatriz.c
 * \brief  Funções para manipular a matriz
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
/// Função para libertar a memória usada para a matriz
/// </summary>
/// <param name="inicio">Endereço do início da matriz</param>
void LibertarMemoria(Matriz* matriz) {
    Elemento* aux = matriz->inicio;
    //Liberta a memória da estrutura de dados
    free(matriz);
    //Percorre pela matriz e liberta a memória de cada elemento
    while (aux->prox != NULL) {
        Elemento* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    //Liberta a memória do elemento auxiliar da função
    free(aux);
}

/// <summary>
/// Função para reservar espaço na memória para um elemento já atribúido um número inteiro
/// </summary>
/// <param name="inteiro">Número inteiro para o elemento da matriz</param>
/// <returns>Endereço do elemento na memória</returns>
Elemento* CriarElemento(int inteiro) {
    //Reserva espaço na memória para um elemento
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento));
    if (aux == NULL) return NULL; //Devolve NULL se não reservou
    aux->inteiro = inteiro; //Atribui o número inteiro do elemento
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
    //Reserva espaço na memória para a matriz
    Matriz* aux = (Matriz*)malloc(sizeof(Matriz));
    if (aux == NULL) return NULL;
    //Preenche os campos da matriz
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
/// <returns>Elemento início da matriz</returns>
Elemento* InserirElemento(Elemento* inicio, Elemento* nova, bool novaLinha) {
    if (nova == NULL) return inicio;
    //Devole o endereço do elemento nova se o elemento incio é nulo
    if (inicio == NULL) inicio = nova;
    else {
        Elemento* aux = inicio;
        //Percorre a matriz(tipo lista) até chegar ao valor nulo
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
        //Se o primeiro elemento é de uma nova linha vai inserir o endereço do primeiro elemento á linha anterior
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

/// <summary>
/// Função altera o número inteiro do elemento na matriz dado as coordenadas
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="coluna">Coluna selecionada</param>
/// <param name="linha">Linha selecionada</param>
/// <param name="novoInteiro">Novo número</param>
/// <returns>Endereço do elemento alterado</returns>
Elemento* AlterarElemento(Matriz* matriz, int coluna, int linha, int novoInteiro) {
    if (matriz == NULL) return NULL; //Se a matriz é nula
    //Verifica se as coordenadas dadas não passam do limite da matriz na memória
    if (matriz->colunas < coluna || matriz->linhas < linha) {
        printf("Limite de linhas ou colunas excedido, verifique se deu a coordenada correta.\n");
        return NULL;
    }
    Elemento* aux = matriz->inicio;
    //Percorre a matriz por linhas
    for (int i = 0; i < linha-1; i++) {
        aux = aux->proxlinha;
    }
    //Percorre as colunas da linha
    for (int i = 0; i < coluna-1; i++) {
        aux = aux->prox;
    }
    //Altera o número inteiro do elemento
    aux->inteiro = novoInteiro;
    return aux;
}

//REVER
void AdicionarLinhaColuna(Matriz* matriz, bool adicionarLinha, int posicao, int* valores[]) {
    // Verifica se a posição é válida
    if (posicao < 0 || (adicionarLinha && posicao > matriz->linhas) || (!adicionarLinha && posicao > matriz->colunas)) {
        return;
    }

    Elemento* novoElemento = NULL;
    Elemento* aux = NULL;

    if (adicionarLinha) {
        // Cria um novo elemento para a linha
        novoElemento = CriarElemento(0);
        if (novoElemento == NULL) {
            return;
        }

        // Insere o novo elemento na matriz
        matriz->inicio = InserirElemento(matriz->inicio, novoElemento, true);

        // Ajusta o número de linhas da matriz
        matriz->linhas++;

        // Insere o novo elemento na posição indicada
        for (int i = 0; i < posicao; i++) {
            aux = novoElemento;
            novoElemento = novoElemento->proxlinha;
        }

        // Se a posição não for a última, conecta o novo elemento ao próximo
        if (posicao < matriz->colunas) {
            aux->proxlinha = novoElemento->proxlinha;
        }
    }
    else {
        // Cria um novo elemento para a coluna
        for (int i = 0; i < matriz->linhas; i++) {
            novoElemento = CriarElemento(0);
            if (novoElemento == NULL) {
                return;
            }

            // Insere o novo elemento na matriz
            matriz->inicio = InserirElemento(matriz->inicio, novoElemento, false);

            // Se não for a primeira iteração, conecta o novo elemento ao anterior
            if (i > 0) {
                aux->prox = novoElemento;
            }

            aux = novoElemento;
        }

        // Ajusta o número de colunas da matriz
        matriz->colunas++;

        // Insere o novo elemento na posição indicada
        for (int i = 0; i < posicao; i++) {
            aux = aux->prox;
        }

        // Conecta o novo elemento ao próximo elemento da coluna
        novoElemento->prox = aux->prox;
    }
}

//REVER
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
