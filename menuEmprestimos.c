#include <stdio.h>
#include "funcoesEmprestimos.h"

void menuEmprestimos() {
    int opcao = 0;

    do {
        printf("\n--- MENU EMPRESTIMOS ---\n");
        printf("1 - Realizar emprestimo\n");
        printf("2 - Devolucao\n");
        printf("3 - Renovar emprestimo\n");
        printf("4 - Listar emprestimos ativos\n");
        printf("5 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: realizarEmprestimo(); break;
            case 2: realizarDevolucao(); break;
            case 3: renovarEmprestimo(); break;
            case 4: listarEmprestimosAtivos(); break;
            case 5: break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 5);
}