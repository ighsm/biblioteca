#include <stdio.h>
#include "funcoesLivros.h"

void menuLivros() {
    int opcao = 0;

    do {
        printf("\n--- MENU LIVROS ---\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar por codigo\n");
        printf("4 - Buscar por titulo\n");
        printf("5 - Buscar por autor\n");
        printf("6 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: listarLivros(); break;
            case 3: buscarLivroPorCodigo(); break;
            case 4: buscarLivroPorTitulo(); break;
            case 5: buscarLivroPorAutor(); break;
            case 6: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
}