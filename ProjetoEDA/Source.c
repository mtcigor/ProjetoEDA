/*****************************************************************//**
 * \file   Source.c
 * \brief  Ficheiro origiem para a execução de todas as funções importantes do Trabalho Prático
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma warning (disable: 4996)

#include "DadosFixos.h"
#include "CarregamentoMatriz.h"
#include "ManipulacaoMatriz.h"
#include "OperacoesMatriz.h"
#include "MostrarMatriz.h"
#include <stdio.h>
#include <locale.h>

int main() {

	setlocale(LC_ALL, "Portuguese"); // Muda a linguagem para Português

	// Exercício 2
	Matriz* matriz = CarregarMatriz("matriz.txt");

	// Exercício 3
	Elemento* elemento = AlterarElemento(matriz, 0, 0, 100);

	// Exercício 4
	int arr[] = { 1, 2, 3, 4, 5};
	int tamanho = 5;
	int ac = AdicionarColunas(matriz, 5, arr, tamanho);

	int arr2[] = { 1, 2, 3, 4, 5, 6 };
	int al = AdicionarLinha(matriz, 5, arr2, 6);

	// Exercício 5
	int rl = RemoverLinha(matriz, 5);
	int rc = RemoverColuna(matriz, 5);

	// Exercício 6
	ListagemTabular(matriz);

	// Exercício 7
	int valor = CalcularSomaMaxima(matriz);

	LibertarMemoria(matriz);

	return 0;
}
