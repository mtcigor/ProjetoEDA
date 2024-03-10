/*****************************************************************//**
 * \file   Global.h
 * \brief  Header global com a definição das estruturas de dados e macros para o Projeto
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/
#pragma once

#include <stdbool.h>

#define TAMANHO_NOME_FICHEIRO 50

/// <summary>
/// Estrutura que define o elemento de uma matriz
/// </summary>
typedef struct ElementoMatriz {
	int inteiro;
	struct ElementoMatriz* prox;
	struct ElementoMatriz* proxlinha;
}Elemento;

/// <summary>
/// Estrutura que indica dois valores da matriz no caso as linhas e colunas e o inicio da matriz
/// </summary>
typedef struct Matriz {
	int linhas;
	int colunas;
	struct ElementoMatriz* inicio;
}Matriz;
