/*****************************************************************//**
 * \file   OperacoesMatriz.h
 * \brief  Header com as funções da Biblioteca OperacoesMatriz
 * 
 * \author Igoe a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma once

#include <DadosFixos.h>

 /// <summary>
 /// Função para obter o endereço de um elemento dado as coordenadas
 /// </summary>
 /// <param name="matriz">Endereço da matriz</param>
 /// <param name="linha">Linha do elemento</param>
 /// <param name="coluna">Coluna do elemento</param>
 /// <returns>Endereço do elemento</returns>
Elemento* ObterElemento(Matriz* matriz, int linha, int coluna);
