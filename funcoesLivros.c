#include <stdio.h>
#include <string.h>
#include "dados.h"
#include "funcoesLivros.h"
#include "dados.h"


static void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void cadastrarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido.\n");
        return;
    }

    Livro *l = &livros[totalLivros];

    printf("\n--- CADASTRO DE LIVRO ---\n");

    printf("Codigo: ");
    scanf("%d", &l->codigo);
    limparBuffer();

    printf("Titulo: ");
    fgets(l->titulo, sizeof(l->titulo), stdin);
    l->titulo[strcspn(l->titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(l->autor, sizeof(l->autor), stdin);
    l->autor[strcspn(l->autor, "\n")] = 0;

    printf("Editora: ");
    fgets(l->editora, sizeof(l->editora), stdin);
    l->editora[strcspn(l->editora, "\n")] = 0;

    printf("Ano: ");
    scanf("%d", &l->ano);

    printf("Quantidade de exemplares: ");
    scanf("%d", &l->exemplares);

    l->status = 0; // disponível
    l->emprestimosRealizados = 0;

    totalLivros++;
    printf("\nLivro cadastrado com sucesso!\n");
}

void listarLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE LIVROS ---\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("%d) %d - %s\n", i+1, livros[i].codigo, livros[i].titulo);
    }
}

void buscarLivroPorCodigo() {
    int codigo;
    printf("Digite o codigo do livro: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigo) {
            printf("\nLivro encontrado:\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Editora: %s\n", livros[i].editora);
            printf("Ano: %d\n", livros[i].ano);
            printf("Exemplares: %d\n", livros[i].exemplares);
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

void buscarLivroPorTitulo() {
    char titulo[100];
    limparBuffer();
    printf("Digite o titulo: ");
    fgets(titulo, 100, stdin);
    titulo[strcspn(titulo, "\n")] = 0;

    for (int i = 0; i < totalLivros; i++) {
        if (strstr(livros[i].titulo, titulo)) {
            printf("\nLivro encontrado: %s\n", livros[i].titulo);
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

void buscarLivroPorAutor() {
    char autor[80];
    limparBuffer();
    printf("Digite o autor: ");
    fgets(autor, 80, stdin);
    autor[strcspn(autor, "\n")] = 0;

    for (int i = 0; i < totalLivros; i++) {
        if (strstr(livros[i].autor, autor)) {
            printf("\nLivro encontrado: %s - %s\n", livros[i].autor, livros[i].titulo);
            return;
        }
    }
    printf("Autor nao encontrado.\n");
}