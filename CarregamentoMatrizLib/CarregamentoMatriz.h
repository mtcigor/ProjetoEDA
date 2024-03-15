/*****************************************************************//**
 * \file   FicheirosLib.h
 * \brief  Header para as funções da biblioteca CarregamentoMatriz
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include "DadosFixos.h"

 /// <summary>
 /// Função para carregar os dados para a matriz onde as linhas e colunas são iguais
 /// </summary>
 /// <param name="nomeFicheiro">Nome do ficheiro</param>
 /// <returns>Estrutura de dados Matriz com o número de linhas e colunas e o início elemento da matriz</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO]);

int** MatrizParaArrayBidimensional(Matriz* matriz);