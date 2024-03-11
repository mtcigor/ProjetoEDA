/*****************************************************************//**
 * \file   Source.c
 * \brief  
 * 
 * \author mtcig
 * \date   March 2024
 *********************************************************************/

#include "DadosFixos.h"
#include "CarregamentoMatriz.h"
#include "ManipulacaoMatriz.h"
#include <stdio.h>

int main() {
	Matriz* matriz = CarregarMatriz("matriz.txt");
	Elemento* elemento = AlterarElemento(matriz, 1, 1, 44);
	int arr[] = { 1, 2, 3, 4, 5 };
	AdicionarLinha(matriz, arr, tamanho);
	LibertarMemoria(matriz);
	return 0;
}
