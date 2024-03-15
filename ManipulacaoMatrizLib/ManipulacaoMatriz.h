/*****************************************************************//**
 * \file   ManipulacaoMatriz.h
 * \brief  Header com as funções da biblioteca ManipulacaoMatriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include "DadosFixos.h"
#include <stdbool.h>

 /// <summary>
 /// Função para libertar a memória usada para a matriz
 /// </summary>
 /// <param name="inicio">Endereço do início da matriz</param>
void LibertarMemoria(Matriz* inicio);

/// <summary>
/// Função para reservar espaço na memória para um elemento já atribúido um número inteiro
/// </summary>
/// <param name="inteiro">Número inteiro para o elemento da matriz</param>
/// <returns>Endereço do elemento na memória</returns>
Elemento* CriarElemento(int inteiro);

/// <summary>
/// Inicializa a estrutura com dados da matriz como linhas e colunas e também o primeiro elemento da matriz
/// </summary>
/// <param name="linhas">Número de linhas da matriz</param>
/// <param name="colunas">Número de colunas da matriz</param>
/// <param name="inicio">Endereço do primeiro elemento da matriz</param>
/// <returns>Endereço dos dados da matriz</returns>
Matriz* AtribuirMatriz(int linhas, int colunas, Elemento* inicio);

/// <summary>
/// Função para inserir o elemento novo á matriz
/// </summary>
/// <param name="inicio">Início da matriz</param>
/// <param name="nova">Novo elemento para inserir</param>
/// <param name="novaLinha">Váriavel de controlo se o elemento é de uma nova linha</param>
/// <returns>Elemento início da matriz</returns>
Elemento* InserirElemento(Elemento* inicio, Elemento* nova, bool novaLinha);

/// <summary>
/// Função altera o número inteiro do elemento na matriz dado as coordenadas
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="coluna">Coluna do elemento</param>
/// <param name="linha">Linha do elemento</param>
/// <param name="novoInteiro">Novo número</param>
/// <returns>Endereço do elemento alterado</returns>
Elemento* AlterarElemento(Matriz* matriz, int coluna, int linha, int novoInteiro);

/// <summary>
/// Função para adicionar uma linha dado uma posição e um array de valores
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="posicao">Número da posição a adicionar a nova linha</param>
/// <param name="valores">Array com os valores para adicionar na matriz</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int AdicionarLinha(Matriz* matriz, int posicao, int valores[], int tamanho);

/// <summary>
/// Função para adicionar uma coluna dado uma posição e um array de valores
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="posicao">Número da posição a adicionar a nova linha</param>
/// <param name="valores">Array com os valores para adicionar na matriz</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int AdicionarColunas(Matriz* matriz, int posicao, int valores[], int tamanho);

/// <summary>
/// Função para remover uma linha selecionada na matriz
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="linha">Número da linha para remover</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int RemoverLinha(Matriz* matriz, int linha);

/// <summary>
/// Função para remover uma coluna selecionada na matriz
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="posicao">Número da coluna para remover</param>
/// <returns>Se devolver 0 a função encontrou um erro inesperado, 1 se executou tudo até o final</returns>
int RemoverColuna(Matriz* matriz, int posicao);
