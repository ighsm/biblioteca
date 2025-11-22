#include <stdio.h>
#include "menuEmprestimos.h"
#include "funcoes.h"
#include "models.h"
int realizarEmprestimo() {return 0;}
int listarEmprestimos() {return 0;}

int menuEmprestimos(){
    printf("MENU DE EMPRESTIMOS.\n");
    int opcao = 0;
    while(opcao != 3){
    printf("[1] Realizar emprestimo. \n");
    printf("[2] Listar emprestimos.\n");
    printf("[3] Voltar\n");
    scanf("%d", &opcao);
        switch(opcao){
            case 1:
                realizarEmprestimo();
                break;
            case 2:
                listarEmprestimos();
                break;
            case 3:
                break;
            default: printf("Opcao invalida ! Tente novamente.\n");
            }
    }
        return 0;
}