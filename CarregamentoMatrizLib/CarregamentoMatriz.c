/*****************************************************************//**
 * \file   CarregamentoMatriz.c
 * \brief  Biblioteca encarregada de carregar os dados da matriz para a memória do programa
 * 
 * \author Igor a27977@alunos.ipca.pt
 * \date   March 2024
 *********************************************************************/

#pragma warning (disable: 4996)

#include "DadosFixos.h"
#include "ManipulacaoMatriz.h"
#include <stdio.h>

/// <summary>
/// Função para carregar os dados para a matriz onde as linhas e colunas são iguais
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro</param>
/// <returns>Estrutura de dados Matriz com o número de linhas e colunas e o início elemento da matriz</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO]) {
    //Definir as variáveis
    int elementoInt; //Elemento da matriz
    int coluna = 0, linha = 0; //Contadores de colunas e linhas
    bool inicioLinha = false; //Bool para controlar o primeiro fim de linha
    bool limColuna = false; //Bool para controlar o limite de colunas

    //Inicializar o ficheiro
    FILE* txtApontador = fopen(nomeFicheiro, "r");
    if (txtApontador == NULL) {
        printf("Erro na leitura do ficheiro.\n");
        return NULL;
    }

    //Inicializar elementos
    Elemento* elemento;
    Elemento* inicio = NULL;

    //Loop para percorrer a matriz do ficheiro de texto
    while (fscanf(txtApontador, "%d", &elementoInt) != EOF) { //Elemento número inteiro
        char eol = fgetc(txtApontador);//Obtém o carácter ao lado do número

        //Fim de linha que insere o elemento, faz a contagem da coluna
        if (eol != ';') {
            Elemento* elemento = CriarElemento(elementoInt);
            inicio = InserirElemento(inicio, elemento, false);
            if (limColuna != true) coluna++;
            linha++;
            //Variáveis de controlo
            inicioLinha = true;
            limColuna = true;
        }
        //Fim do ficheiro que insere o ultímo elemento da matriz
        else if (eol == EOF) {
            Elemento* elemento = CriarElemento(elementoInt);
            inicio = InserirElemento(inicio, elemento, false);
            linha++;
        }
        //Elemento seguinte não primeiro da linha nova
        else if (inicioLinha == false) {
            Elemento* elemento = CriarElemento(elementoInt);
            inicio = InserirElemento(inicio, elemento, false);
            if (limColuna != true) coluna++;
        }
        //Elemento seguinte primeiro da linha nova
        else if (inicioLinha == true) {
            Elemento* elemento = CriarElemento(elementoInt);
            inicio = InserirElemento(inicio, elemento, true);
            inicioLinha = false;
        }

    }
    Matriz* matriz = AtribuirMatriz(linha, coluna, inicio);
    return matriz;
}