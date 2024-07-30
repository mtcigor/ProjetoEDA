/*****************************************************************//**
 * \file   Global.h
 * \brief  Header global com a defini��o das estruturas de dados e macros para o Projeto
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
	/// Endere�o do pr�ximo elemento
	struct ElementoMatriz* prox;
	/// Apenas no primeiro elemento da linha, endere�o da pr�xima linha
	struct ElementoMatriz* proxlinha;
}Elemento;

/// <summary>
/// Estrutura que indica dois valores da matriz no caso as linhas e colunas e o inicio da matriz
/// </summary>
typedef struct Matriz {
	/// N�mero de linhas da matriz
	int linhas;
	/// N�mero de colunas da matriz
	int colunas;
	/// Endere�o do in�cio da matriz
	struct ElementoMatriz* inicio;
}Matriz;
