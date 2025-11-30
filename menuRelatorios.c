#include <stdio.h>
#include "relatorios.h"

void menuRelatorios() {
    int op;

    do {
        printf("\n=== MENU RELATORIOS ===\n");
        printf("1 - Livros mais emprestados\n");
        printf("2 - Usuarios em atraso\n");
        printf("3 - Busca avancada de livros\n");
        printf("4 - Voltar\n");
        scanf("%d", &op);

        switch(op) {
            case 1: relatorioLivrosMaisEmprestados(); break;
            case 2: relatorioUsuariosAtrasados(); break;
            case 3: buscaAvancadaLivros(); break;
            case 4: break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 4);
}