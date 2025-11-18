#include <stdio.h>
#include "menulivros.h"
int menuEmprestimos() { return 0;}
int menuUsuarios() { return 0;}


int main(){
    int opcao = 0;
    while(opcao != 4){
    printf("SISTEMA DE BIBLIOTECA\n");
    printf("[1] Gerenciar usuarios \n");
    printf("[2] Gerenciar livros \n");
    printf("[3] Emprestimos \n");
    printf("[4] Sair \n");
    printf("Escolha uma opcao \n");
    scanf("%d", &opcao);

        switch(opcao){
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
                printf("Sistema encerrado. \n");
                break;
            default:
                printf("Opcao invalida! Tente novamente. \n");

        }
    }
        return 0;
}