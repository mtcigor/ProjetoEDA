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
	LibertarMemoria(matriz);
	return 0;
}
