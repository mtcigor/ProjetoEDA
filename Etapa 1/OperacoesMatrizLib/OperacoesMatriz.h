/*****************************************************************//**
 * \file   OperacoesMatriz.h
 * \brief  Header com as fun��es da Biblioteca OperacoesMatriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include "DadosFixos.h"

 /// <summary>
 /// Fun��o para obter o endere�o de um elemento dado as coordenadas
 /// </summary>
 /// <param name="matriz">Endere�o da matriz</param>
 /// <param name="linha">Linha do elemento</param>
 /// <param name="coluna">Coluna do elemento</param>
 /// <returns>Endere�o do elemento</returns>
Elemento* ObterElemento(Matriz* matriz, int linha, int coluna);

/// <summary>
/// Fun��o para preencher uma arra bidimensional com os inteiros da matriz
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <returns>Endere�o do primeiro elemento da array bidimensional</returns>
int** MatrizParaArrayBidimensional(Matriz* matriz);

/// <summary>
/// Fun��o auxiliar para calcular a soma m�xima de forma recursiva
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <param name="biMatriz">Endere�o do array bidimensional</param>
/// <param name="linha_atual">Linha atual</param>
/// <param name="colunas_usadas">Colunas usadas para evitar o uso de colunas inv�lidas</param>
/// <returns>Soma m�xima poss�vel</returns>
int CalcularSomaMaximaRecursiva(Matriz* matriz, int** biMatriz, int linha_atual, int* colunas_usadas);

/// <summary>
/// Fun��o principal para calcular a soma m�xima de forma inteligente
/// </summary>
/// <param name="matriz">Endere�o da matriz</param>
/// <returns>Soma m�xima poss�vel da matriz</returns>
int CalcularSomaMaxima(Matriz* matriz);
