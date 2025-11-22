#include <stdio.h>
#include "menulivros.h"
#include "funcoes.h"
#include "models.h"
int buscarLivros() {return 0;}
int listarLivros() {return 0;}
int cadastroLivro() {return 0;}

int menuLivros(){
    int opcao = 0;
    while(opcao != 4){
    printf("MENU LIVROS. \n");
        printf("[1] Cadastrar livros. \n");
        printf("[2] Listar livros. \n");
        printf("[3] Pesquisar livros. \n");
        printf("[4] Voltar. \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastroLivro();
                break;
            case 2:
                listarLivros();
                break;
            case 3:
                buscarLivros();
                break;
            case 4:
                break; //Voltar para o inicio
            default: printf("Opcao invalida! Tente novamente.");
        }
    }
    return 0;
}