/*****************************************************************//**
 * \file   ManipulacaoMatriz.h
 * \brief  
 * 
 * \author mtcig
 * \date   March 2024
 *********************************************************************/

#pragma once
#include "DadosFixos.h"
#include <stdbool.h>

 /// <summary>
 /// Função para libertar a memória usada para a matriz
 /// </summary>
 /// <param name="inicio">Endereço do início da matriz</param>
void LibertarMemoria(Elemento* inicio);

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
/// <returns>Início da matriz</returns>
Elemento* InserirElemento(Elemento* inicio, Elemento* nova, bool novaLinha);


