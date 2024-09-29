// funcoes.c
#include "bibli.h"

Produto produtos[MAX_PRODUTOS];
ItemCarrinho carrinho[MAX_CARRINHO];
int totalProdutos = 0;
int totalCarrinho = 0;

// Função para exibir as informações de um produto
void infoProduto(Produto prod) {
    printf("Codigo: %d | Nome: %s | Preco: %.2f\n", prod.codigo, prod.nome, prod.preco);
}

// Função para buscar um produto pelo código
int pegarProdutoPorCodigo(int codigo) {
    int i;
    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Função para verificar se um produto já está no carrinho
int temNoCarrinho(int codigo) {
    int i;
    for (i = 0; i < totalCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Função para cadastrar um novo produto
void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        system("pause");

        return;
    }

    Produto novoProduto;
    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);

    // Verificar se o produto já existe
    if (pegarProdutoPorCodigo(novoProduto.codigo) != -1) {
        printf("Produto com esse codigo ja existe!\n");
        system("pause");

        return;
    }

    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto.nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
    printf("Produto cadastrado com sucesso!\n");
    system("pause");

}

// Função para listar todos os produtos cadastrados
void listarProdutos() {
    int i;
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado!\n");
        system("pause");
        return;
    }

    printf("---- Lista de Produtos ----\n");
    for (i = 0; i < totalProdutos; i++) {
        infoProduto(produtos[i]);
    }
    printf("--------------------------\n");
    system("pause");
}

// Função para adicionar produtos ao carrinho
void comprarProduto() {
    int codigo, quantidade;
    printf("Digite o codigo do produto para comprar: ");
    scanf("%d", &codigo);

    int indiceProduto = pegarProdutoPorCodigo(codigo);
    if (indiceProduto == -1) {
        printf("Produto nao encontrado!\n");
        system("pause");
        return;
    }

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    int indiceCarrinho = temNoCarrinho(codigo);
    if (indiceCarrinho != -1) {
        carrinho[indiceCarrinho].quantidade += quantidade;
    } else {
        carrinho[totalCarrinho].produto = produtos[indiceProduto];
        carrinho[totalCarrinho].quantidade = quantidade;
        totalCarrinho++;
    }

    printf("Produto adicionado ao carrinho!\n");
    system("pause");
}

// Função para visualizar o carrinho
void visualizarCarrinho() {
    int i;
    if (totalCarrinho == 0) {
        printf("Carrinho vazio!\n");
        system("pause");
        return;
    }

    printf("---- Carrinho ----\n");
    for (i = 0; i < totalCarrinho; i++) {
        printf("Produto: %s | Quantidade: %d | Preco: %.2f\n",
               carrinho[i].produto.nome, carrinho[i].quantidade, carrinho[i].produto.preco);
    }
    printf("-----------------\n");
    system("pause");
}

// Função para fechar o pedido e calcular o valor total
void fecharPedido() {
    int i;
    if (totalCarrinho == 0) {
        printf("Carrinho vazio! Nao e possivel fechar o pedido.\n");
        system("pause");
        return;
    }

    float total = 0;
    printf("---- Fatura ----\n");
    for (i = 0; i < totalCarrinho; i++) {
        float subtotal = carrinho[i].quantidade * carrinho[i].produto.preco;
        printf("Produto: %s | Quantidade: %d | Subtotal: %.2f\n", 
               carrinho[i].produto.nome, carrinho[i].quantidade, subtotal);
        total += subtotal;
    }
    printf("Valor total: %.2f\n", total);

    // Esvazia o carrinho após o pedido ser fechado
    totalCarrinho = 0;
    printf("Pedido fechado com sucesso!\n");
    system("pause");
}

// Função para remover um produto do carrinho
void removerProdutoCarrinho() {
    int codigo, index;

    printf("Digite o codigo do produto que deseja remover do carrinho: ");
    scanf("%d", &codigo);

    // Verifica se o produto está no carrinho
    index = temNoCarrinho(codigo);
    if (index != -1) {
        // Remove o produto do carrinho, ajustando a quantidade
        printf("Produto %s removido do carrinho.\n", carrinho[index].produto.nome);
        // Zera a quantidade do produto removido
        carrinho[index].quantidade = 0;
        totalCarrinho--; // Diminui o total de itens no carrinho
    } else {
        printf("Produto nao encontrado no carrinho.\n");
    }
}

// Função para atualizar informações de um produto
void atualizarProduto() {
    int codigo, index;
    char novoNome[30];
    float novoPreco;

    printf("Digite o codigo do produto que deseja atualizar: ");
    scanf("%d", &codigo);

    // Verifica se o produto está cadastrado
    index = pegarProdutoPorCodigo(codigo);
    if (index != -1) {
        // Solicita novas informações
        printf("Digite o novo nome do produto: ");
        scanf(" %[^\n]", novoNome);
        printf("Digite o novo preco do produto: ");
        scanf("%f", &novoPreco);

        // Atualiza as informações do produto
        strcpy(produtos[index].nome, novoNome);
        produtos[index].preco = novoPreco;
        printf("Produto atualizado com sucesso!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

