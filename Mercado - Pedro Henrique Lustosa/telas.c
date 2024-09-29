// telas.c
#include "funcoes.c"

void menu() {
    int opcao;

    do {
    	system("cls");
        printf("---- Menu ----\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Atualizar Produto\n"); 
        printf("3. Listar Produtos\n");
        printf("4. Comprar Produto\n");
        printf("5. Visualizar Carrinho\n");
        printf("6. Remover Produto do Carrinho\n");
        printf("7. Fechar Pedido\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    	system("cls");

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
            	atualizarProduto();
            	break;
            case 3:
                listarProdutos();
                break;
            case 4:
                comprarProduto();
                break;
            case 5:
                visualizarCarrinho();
                break;
            case 6:
            	removerProdutoCarrinho();
            	break;
            case 7:
                fecharPedido();
                break;
            case 8:
                printf("Saindo...\n");
                system("pause");
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
        }
    } while (opcao != 8);
}

