#include <stdio.h>
#include "dados.h"

//Cadastro de usuario
void cadastroUsuario() {
    printf("\n CADASTRO DE USUARIO \n");

    printf("Matricula: ");
    scanf("%d", &usuarios[totalUsuarios].matricula);

    printf("Nome: ");
    fflush(stdin);
    fgets(usuarios[totalUsuarios].nome, 100, stdin);

    printf("Curso: ");
    fflush(stdin);
    fgets(usuarios[totalUsuarios].curso, 50, stdin);

    printf("Telefone: ");
    fflush(stdin);
    fgets(usuarios[totalUsuarios].telefone, 15, stdin);

    printf("Dia do cadastro: ");
    scanf("%d", &usuarios[totalUsuarios].dataCadastro.dia);

    printf("Mes: ");
    scanf("%d", &usuarios[totalUsuarios].dataCadastro.mes);

    printf("Ano: ");
    scanf("%d", &usuarios[totalUsuarios].dataCadastro.ano);

    totalUsuarios++;

    printf("\nUsuario cadastrado com sucesso!\n");
}
int buscarUsuario() {
    printf("\nFuncao buscarUsuario ainda nao implementada.\n");
}