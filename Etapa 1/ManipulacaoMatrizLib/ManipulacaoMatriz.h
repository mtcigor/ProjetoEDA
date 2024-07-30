/*****************************************************************//**
 * \file   ManipulacaoMatriz.h
 * \brief  Header com as fun��es da biblioteca ManipulacaoMatriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include "DadosFixos.h"
#include <stdbool.h>

 /// <summary>
 /// Fun��o para libertar a mem�ria usada para a matriz
 /// </summary>
 /// <param name="inicio">Endere�o do in�cio da matriz</param>
void LibertarMemoria(Matriz* inicio);

/// <summary>
/// Fun��o para reservar espa�o na mem�ria para um elemento j� atrib�ido um n�mero inteiro
/// </summary>
/// <param name="inteiro">N�mero inteiro para o elemento da matriz</param>
/// <returns>Endere�o do elemento na mem�ria</returns>
Elemento* CriarElemento(int inteiro);

/// <summary>
/// Inicializa a estrutura com dados da matriz como linhas e colunas e tamb�m o primeiro elemento da matriz
/// </summary>
/// <param name="linhas">N�mero de linhas da matriz</param>
/// <param name="colunas">N�mero de colunas da matriz</param>
/// <param name="inicio">Endere�o do primeiro elemento da matriz</param>
/// <returns>Endere�o dos dados da matriz</returns>
Matriz* AtribuirMatriz(int linhas, int colunas, Elemento* inicio);

/// <summary>
/// Fun��o para inserir o elemento novo � matriz
/// </summary>
/// <param name="inicio">In�cio da matriz</param>
/// <param name="nova">Novo elemento para inserir</param>
/// <param name="novaLinha">V�riavel de controlo se o elemento � de uma nova linha</param>
/// <returns>Elemento in�cio da matriz</returns>
Elemento* InserirElemento(Elemento* inicio, Elemento* nova, bool novaLinha);

/// <summary>
/// Fun��o altera o n�mero inteiro do elemento na matriz dado as coordenadas
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="coluna">Coluna do elemento</param>
/// <param name="linha">Linha do elemento</param>
/// <param name="novoInteiro">Novo n�mero</param>
/// <returns>Endere�o do elemento alterado</returns>
Elemento* AlterarElemento(Matriz* matriz, int coluna, int linha, int novoInteiro);

/// <summary>
/// Fun��o para adicionar uma linha dado uma posi��o e um array de valores
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="posicao">N�mero da posi��o a adicionar a nova linha</param>
/// <param name="valores">Array com os valores para adicionar na matriz</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>Se devolver 0 a fun��o encontrou um erro inesperado, 1 se executou tudo at� o final</returns>
int AdicionarLinha(Matriz* matriz, int posicao, int valores[], int tamanho);

/// <summary>
/// Fun��o para adicionar uma coluna dado uma posi��o e um array de valores
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="posicao">N�mero da posi��o a adicionar a nova linha</param>
/// <param name="valores">Array com os valores para adicionar na matriz</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>Se devolver 0 a fun��o encontrou um erro inesperado, 1 se executou tudo at� o final</returns>
int AdicionarColunas(Matriz* matriz, int posicao, int valores[], int tamanho);

/// <summary>
/// Fun��o para remover uma linha selecionada na matriz
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="linha">N�mero da linha para remover</param>
/// <returns>Se devolver 0 a fun��o encontrou um erro inesperado, 1 se executou tudo at� o final</returns>
int RemoverLinha(Matriz* matriz, int linha);

/// <summary>
/// Fun��o para remover uma coluna selecionada na matriz
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="posicao">N�mero da coluna para remover</param>
/// <returns>Se devolver 0 a fun��o encontrou um erro inesperado, 1 se executou tudo at� o final</returns>
int RemoverColuna(Matriz* matriz, int posicao);
