#include <stdio.h>
#include "menuUsuarios.h"
#include "funcaoUsuario.h"


int menuUsuarios(){
    int opcao = 0;
    while(opcao != 4){
        printf("\n-----MENU DE USUARIOS-----\n");
        printf("[1] Cadastrar usuario.\n");
        printf("[2] Buscar usuario (por matricula). \n");
        printf("[3] Listar ususarios\n");
        printf("[4] Voltar.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastroUsuario();
                break;
            case 2:
                buscarUsuario();
                break;
            case 3:
                listarUsuarios();
                break;
            case 4:
                break; //Voltar para o inicio
        default: 
            printf("Opcao invalida ! Tente novamente.");
        }
    }
    }
    
        

    
    
