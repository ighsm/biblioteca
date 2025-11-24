#include <stdio.h>
#include "menuUsuarios.h"
#include "funcoes.h"
#include "models.h"


int menuUsuarios(){
    int opcao = 0;
    while(opcao != 3){
        printf("\nMENU DE USUARIOS \n");
        printf("[1] Cadastrar usuario.\n");
        printf("[2] Buscar usuario (por matricula). \n");
        printf("[3] Voltar.");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastroUsuario();
                break;
            case 2:
                buscarUsuario();
                break;
            case 3:
                break; //Voltar para o inicio
        default: 
            printf("Opcao invalida ! Tente novamente.");
        }
    }
    }
    
        

    
    
