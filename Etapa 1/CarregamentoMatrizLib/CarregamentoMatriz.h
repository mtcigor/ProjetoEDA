/*****************************************************************//**
 * \file   FicheirosLib.h
 * \brief  Header para as fun��es da biblioteca CarregamentoMatriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include "DadosFixos.h"

 /// <summary>
 /// Fun��o para carregar os dados para a matriz onde as linhas e colunas s�o iguais
 /// </summary>
 /// <param name="nomeFicheiro">Nome do ficheiro</param>
 /// <returns>Estrutura de dados Matriz com o n�mero de linhas e colunas e o in�cio elemento da matriz</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO]);

int** MatrizParaArrayBidimensional(Matriz* matriz);