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
	//Elemento* elemento = AlterarElemento(matriz, 0, 0, 44);
	int arr[] = { 1, 2, 3, 4, 5};
	int tamanho = 5;
	//AdicionarColunas(matriz, 0, arr, tamanho);
	//RemoverLinha(matriz, 4);
	RemoverColuna(matriz, 4);
	LibertarMemoria(matriz);
	return 0;
}
