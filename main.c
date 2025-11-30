#include <stdio.h>
#include "menuLivros.h"
#include "menuUsuarios.h"
#include "menuEmprestimos.h"
#include "menuRelatorios.h"
#include "arquivos.h"   // ← IMPORTANTE para salvar/carregar

int main() {

    carregarTudo();   // ← CARREGA ANTES DE COMEÇAR

    int opcao = 0;

    while (opcao != 5) {
        printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
        printf("[1] Gerenciar usuarios\n");
        printf("[2] Gerenciar livros\n");
        printf("[3] Emprestimos\n");
        printf("[4] Relatorios\n");
        printf("[5] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuUsuarios();
                break;
            case 2:
                menuLivros();
                break;
            case 3:
                menuEmprestimos();
                break;
            case 4:
                menuRelatorios();
                break;
            case 5:
                printf("Sistema encerrado.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    salvarTudo();   // ← SALVA ANTES DE SAIR

    return 0;
}
