// bibli.h
#ifndef BIBLI_H
#define BIBLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 50
#define MAX_CARRINHO 50

// Estrutura de Produto
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

// Estrutura de Item no Carrinho
typedef struct {
    Produto produto;
    int quantidade;
} ItemCarrinho;

// Declaração de variáveis globais
extern Produto produtos[MAX_PRODUTOS];
extern ItemCarrinho carrinho[MAX_CARRINHO];
extern int totalProdutos;
extern int totalCarrinho;

// Declaração de funções
void infoProduto(Produto prod);
int pegarProdutoPorCodigo(int codigo);
int temNoCarrinho(int codigo);
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
void removerProdutoCarrinho();
void atualizarProduto();
void menu();

#endif // BIBLI_H

