/*****************************************************************//**
 * \file   ManipulacaoMatriz.c
 * \brief  Biblioteca com várias funções para manipular a matriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma warning (disable: 4996)

#include "DadosFixos.h"
#include "OperacoesMatriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// <summary>
/// Função para libertar a memória usada para a matriz
/// </summary>
/// <param name="inicio">Endereço do início da matriz</param>
void LibertarMemoria(Matriz* matriz) {
    if (matriz == NULL) {
        printf("Endereço da matriz inválido.\n");
        return;
    }

    Elemento* aux = matriz->inicio;
    // Liberta a memória da estrutura de dados
    free(matriz);

    // Percorre pela matriz e liberta a memória de cada elemento
    while (aux->prox != NULL) {
        Elemento* temp = aux;
        aux = aux->prox;
        free(temp);
    }

    // Liberta a memória do elemento auxiliar da função
    free(aux);
}

/// <summary>
/// Função para reservar espaço na memória para um elemento já atribúido um número inteiro
/// </summary>
/// <param name="inteiro">Número inteiro para o elemento da matriz</param>
/// <returns>Endereço do elemento na memória</returns>
Elemento* CriarElemento(int inteiro) {
    // Reserva espaço na memória para um elemento
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento));

    if (aux == NULL) return NULL; // Devolve NULL se não reservou   

    aux->inteiro = inteiro; // Atribui o número inteiro do elemento
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
    // Reserva espaço na memória para a matriz
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
    // Devolve o endereço do elemento nova se o elemento início é nulo
    if (inicio == NULL) inicio = nova;
    else {
        Elemento* aux = inicio;
        // Percorre a matriz(tipo lista) até chegar ao valor nulo
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;

        // Se o primeiro elemento é de uma nova linha vai inserir o endereço do primeiro elemento á linha anterior
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
/// <param name="coluna">Coluna do elemento</param>
/// <param name="linha">Linha do elemento</param>
/// <param name="novoInteiro">Novo número</param>
/// <returns>Endereço do elemento alterado</returns>
Elemento* AlterarElemento(Matriz* matriz, int coluna, int linha, int novoInteiro) {
    Elemento* aux = ObterElemento(matriz, linha, coluna);

    // Altera o número inteiro do elemento
    if (aux == NULL) {
        return NULL;
    }
    aux->inteiro = novoInteiro;

    return aux;
}

/// <summary>
/// Função para adicionar uma linha dado uma posição e um array de valores
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="posicao">Número da posição a adicionar a nova linha</param>
/// <param name="valores">Array com os valores para adicionar na matriz</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int AdicionarLinha(Matriz* matriz, int posicao, int valores[], int tamanho) {
    //Verificação de parâmetros
    if (matriz == NULL || posicao < 0 || posicao > matriz->linhas || tamanho <= 0 || matriz->colunas > tamanho){
    return 0;
    }

    //Cria o novo elemento da linha
    Elemento* primeiroNovoElemento = CriarElemento(valores[0]);
    Elemento* novoElemento = NULL;
    if (primeiroNovoElemento == NULL) return 0;

    Elemento* linhaNova = primeiroNovoElemento;
    for (int i = 1; i < tamanho; i++) {
        novoElemento = CriarElemento(valores[i]);
        if (novoElemento == NULL) return 0;
        while (linhaNova->prox != NULL) {
            linhaNova = linhaNova->prox;
        }
        linhaNova->prox = novoElemento;
    }

    //Insere a nova linha na matriz
    Elemento* aux = matriz->inicio;
    for (int i = 0; i < posicao-1; i++) {
        aux = aux->proxlinha;
    }

    //Se a linha a ser inserida for a primeira
    if (posicao == 0) {
        primeiroNovoElemento->proxlinha = matriz->inicio;
        matriz->inicio = primeiroNovoElemento;
        novoElemento->prox = aux;
    }
    else {
        primeiroNovoElemento->proxlinha = aux->proxlinha;
        aux->proxlinha = primeiroNovoElemento;
        novoElemento->prox = primeiroNovoElemento->proxlinha;
    }

    //Atualiza o número de linhas da matriz
    matriz->linhas++;

    return 1;
}

/// <summary>
/// Função para adicionar uma coluna dado uma posição e um array de valores
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="posicao">Número da posição a adicionar a nova linha</param>
/// <param name="valores">Array com os valores para adicionar na matriz</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int AdicionarColunas(Matriz* matriz, int posicao, int valores[], int tamanho) {
    //Verificação de parâmetros
    if (matriz == NULL || posicao < 0 || posicao > matriz->colunas || tamanho <= 0 || tamanho > matriz->linhas || tamanho < matriz->linhas) {
        return 0;
    }
    //Inicializar os elementos
    Elemento* novoElemento = NULL; //Novo elemento a ser inserido
    Elemento* aux = matriz->inicio; //Elemento que guarda a linha a qual o novo elemento será inserido
    Elemento* aux2 = NULL; //Elemento com a coluna a qual será inserido o novo elemento
    Elemento* anterior = NULL; //Guardar o elemento novo para a próxima interação com outro novo elemento
    Elemento* linhaAnterior = NULL; //Elemento com a primeira posição da linha anterior
    Elemento* anteriorElemento = matriz->inicio; //Elemento anterior se o elemento novo está a ser adicionado no "meio" da matriz
    int n = -1; //Inteiro para controlar a interação de linhas
    bool inicio = true;
    
    for (int i = 0; i <= matriz->colunas-1; i++) {
        //Se a posição é 0 e não é o início
        if (inicio != true && posicao == 0) {
            aux = novoElemento->proxlinha;
        }
        else {
            if (inicio != true) aux = aux->proxlinha;
        }
        n++; 
        aux2 = aux;
        novoElemento = CriarElemento(valores[n]); //Novo elemento da array dada
        //Ciclo for para encontrar o elemento que está na coluna pedida usando a variável posição
        for (int k = 0; k < posicao; k++) {
            aux2 = aux2->prox;
        }
        novoElemento->prox = aux2;
        //Se a posicao for 0, o campo proxlinha do novoElemento obtêm o endereço da próxima linha
        if(posicao == 0)novoElemento->proxlinha = aux2->proxlinha;
        //Muda o início da matriz para o novo elemento
        if (n == 0 && posicao == 0) {
            matriz->inicio = novoElemento;
        }
        /*Se não for a primeira linha e a posição dos elementos a ser inseridos é 0, 
        o elemento anterior ao novo elemento guarda o endereço do novo elemento*/
        else if (n != 0 && posicao == 0) {
            anterior->proxlinha = novoElemento;
        }
        //O elemento anterior obtêm o endereço do novo Elemento para ligar a lista
        if (posicao != 0 && inicio == true) {
            for (int e = 0; e < posicao - 1; e++) {
                anteriorElemento = anteriorElemento->prox;
            }
            anteriorElemento->prox = novoElemento;
        }
        if (inicio != true) {
            for (int l = 0; l < matriz->colunas; l++) {
                linhaAnterior = linhaAnterior->prox;
            }
            linhaAnterior->prox = novoElemento;
        }
        //Remover o endereço proxlinha quando o primeiroElemento da linha é movido
        if (posicao != matriz->colunas) {
            aux2->proxlinha = NULL;
        }
        anterior = novoElemento;
        linhaAnterior = novoElemento;
        inicio = false;
    }

    //Atualiza o número de colunas da matriz
    matriz->colunas++;

    return 1;
}

/// <summary>
/// Função para remover uma linha selecionada na matriz
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="linha">Número da linha para remover</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int RemoverLinha(Matriz* matriz, int linha) {
    //Verificação dos parâmetros
    if (matriz == NULL || linha < 0 || linha >= matriz->linhas) {
        return 0;
    }

    //Ponteiro para o início da linha a remover
    Elemento* linhaToRemove = matriz->inicio;
    for (int i = 0; i < linha; i++) {
        linhaToRemove = linhaToRemove->proxlinha;
    }
    //Ponteiro para o elemento anterior à linha a remover
    Elemento* anterior = NULL;
    Elemento* atual = matriz->inicio;
    while (atual != linhaToRemove) {
        anterior = atual;
        atual = atual->proxlinha;
    }
    //Se a linha a remover for a primeira
    if (anterior == NULL) {
        matriz->inicio = linhaToRemove->proxlinha;
        anterior = matriz->inicio;
    }
    else {
        anterior->proxlinha = linhaToRemove->proxlinha;
    }
    //Libertar a memória da linha removida
    Elemento* aux = linhaToRemove;
    while (aux != NULL) {
        Elemento* temp = aux;
        aux = aux->prox;
        free(temp);
        //Parar o loop se chegou ao fim da linha
        if (matriz->inicio == aux || anterior->proxlinha == aux) break;
        
    }
    //Liga o ultímo elemento da linha anterior ao primeiro elemento da proxima linha
    if (aux == anterior->proxlinha) {
        Elemento* aux2 = anterior;
        for(int i = 0; i < matriz->colunas-1; i++){
            aux2 = aux2->prox;
        }
        aux2->prox = anterior->proxlinha;
    }
    // Atualizar o número de linhas da matriz
    matriz->linhas--;
    return 1;
}

/// <summary>
/// Função para remover uma coluna selecionada na matriz
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="posicao">Número da coluna para remover</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int RemoverColuna(Matriz* matriz, int posicao) {
    // Verificação de parâmetros
    if (matriz == NULL || posicao < 0 || posicao >= matriz->colunas) {
        return 0;
    }

    Elemento* colunaToRemove = NULL;
    Elemento* proxLinha = matriz->inicio->proxlinha;
    bool inicio = true;
    //Ciclo para mover de linha a linha
    for (int l = 0; l < matriz->linhas; l++) {
        if (inicio == true) {
            colunaToRemove = matriz->inicio;
            
        } 
        else if (posicao != 0) {
            colunaToRemove = proxLinha;
            proxLinha = proxLinha->proxlinha;
        } 
        for (int i = 0; i < posicao; i++) {
            colunaToRemove = colunaToRemove->prox;
        }
        // Ponteiro para o elemento anterior à coluna a remover
        Elemento* anterior = NULL;
        Elemento* atual = matriz->inicio;
        while (atual != colunaToRemove) {
            anterior = atual;
            atual = atual->prox;
        }
        // Se a coluna a remover for a primeira
        if (anterior == NULL) {
            matriz->inicio = colunaToRemove->prox;
            matriz->inicio->proxlinha = colunaToRemove->proxlinha->prox;
        }
        else {
            anterior->prox = colunaToRemove->prox;
            anterior->proxlinha = colunaToRemove->proxlinha;
        }
        // Liberar memória da coluna removida
        while (colunaToRemove != NULL) {
            Elemento* temp = colunaToRemove;
            Elemento* aux = colunaToRemove;
            if (posicao == 0 && aux != NULL) {
                for (int c = 0; c < matriz->colunas-1; c++) {
                    aux = aux->prox;
                }
                if(aux->prox != NULL) aux->prox = aux->prox->prox;
                
            }
            colunaToRemove = colunaToRemove->proxlinha;
            if (colunaToRemove != NULL) {
                if (colunaToRemove->proxlinha != NULL) {
                    colunaToRemove->prox->proxlinha = colunaToRemove->proxlinha->prox;
                }
            }
            free(temp);
        }
        if (posicao == 0) break;
        inicio = false;
    }
    
    // Atualizar o número de colunas da matriz
    matriz->colunas--;

    return 1;
}