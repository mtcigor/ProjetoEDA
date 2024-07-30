/*****************************************************************//**
 * \file   Global.h
 * \brief  Header global com a definição das estruturas de dados e macros para o Projeto
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/
#pragma once

#include <stdbool.h>

#define TAMANHO_NOME_FICHEIRO 50 // Limite do nome do ficheiro

/// <summary>
/// Estrutura que define o elemento de uma matriz
/// </summary>
typedef struct ElementoMatriz {
	/// Valor inteiro do elemento
	int inteiro;
	/// Endereço do próximo elemento
	struct ElementoMatriz* prox;
	/// Apenas no primeiro elemento da linha, endereço da próxima linha
	struct ElementoMatriz* proxlinha;
}Elemento;

/// <summary>
/// Estrutura que indica dois valores da matriz no caso as linhas e colunas e o inicio da matriz
/// </summary>
typedef struct Matriz {
	/// Número de linhas da matriz
	int linhas;
	/// Número de colunas da matriz
	int colunas;
	/// Endereço do início da matriz
	struct ElementoMatriz* inicio;
}Matriz;
