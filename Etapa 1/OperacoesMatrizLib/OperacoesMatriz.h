/*****************************************************************//**
 * \file   OperacoesMatriz.h
 * \brief  Header com as funções da Biblioteca OperacoesMatriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include "DadosFixos.h"

 /// <summary>
 /// Função para obter o endereço de um elemento dado as coordenadas
 /// </summary>
 /// <param name="matriz">Endereço da matriz</param>
 /// <param name="linha">Linha do elemento</param>
 /// <param name="coluna">Coluna do elemento</param>
 /// <returns>Endereço do elemento</returns>
Elemento* ObterElemento(Matriz* matriz, int linha, int coluna);

/// <summary>
/// Função para preencher uma arra bidimensional com os inteiros da matriz
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <returns>Endereço do primeiro elemento da array bidimensional</returns>
int** MatrizParaArrayBidimensional(Matriz* matriz);

/// <summary>
/// Função auxiliar para calcular a soma máxima de forma recursiva
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <param name="biMatriz">Endereço do array bidimensional</param>
/// <param name="linha_atual">Linha atual</param>
/// <param name="colunas_usadas">Colunas usadas para evitar o uso de colunas inválidas</param>
/// <returns>Soma máxima possível</returns>
int CalcularSomaMaximaRecursiva(Matriz* matriz, int** biMatriz, int linha_atual, int* colunas_usadas);

/// <summary>
/// Função principal para calcular a soma máxima de forma inteligente
/// </summary>
/// <param name="matriz">Endereço da matriz</param>
/// <returns>Soma máxima possível da matriz</returns>
int CalcularSomaMaxima(Matriz* matriz);
