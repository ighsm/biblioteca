#include <stdio.h>
#include <string.h>
#include "dados.h"
#include "models.h"
#include "funcaoUsuario.h"

// Função para limpar buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// ----------------------------
// CADASTRO DE USUÁRIO
// ----------------------------
void cadastroUsuario() {

    printf("\n--- CADASTRO DE USUARIO ---\n");

    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Erro: limite maximo de usuarios atingido!\n");
        return;
    }

    printf("Matricula: ");
    scanf("%d", &usuarios[totalUsuarios].matricula);
    limparBuffer();

    printf("Nome: ");
    fgets(usuarios[totalUsuarios].nome, 100, stdin);

    printf("Curso: ");
    fgets(usuarios[totalUsuarios].curso, 50, stdin);

    printf("Telefone: ");
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

// ----------------------------
// BUSCAR USUARIO POR MATRICULA
// ----------------------------
void buscarUsuario() {
    int matricula;
    int encontrado = 0;

    printf("\n--- BUSCA DE USUARIO ---\n");
    printf("Digite a matricula do usuario: ");
    scanf("%d", &matricula);

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].matricula == matricula) {

            printf("\nUsuario encontrado!\n");
            printf("Matricula: %d\n", usuarios[i].matricula);
            printf("Nome: %s", usuarios[i].nome);
            printf("Curso: %s", usuarios[i].curso);
            printf("Telefone: %s", usuarios[i].telefone);
            printf("Data de cadastro: %02d/%02d/%04d\n",
                usuarios[i].dataCadastro.dia,
                usuarios[i].dataCadastro.mes,
                usuarios[i].dataCadastro.ano
            );

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nNenhum usuario encontrado com essa matricula.\n");
    }
}

// ----------------------------
// LISTAR TODOS OS USUÁRIOS
// ----------------------------
void listarUsuarios() {

    printf("\n--- LISTA DE USUARIOS ---\n");

    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        printf("\nUsuario %d:\n", i + 1);
        printf("Matricula: %d\n", usuarios[i].matricula);
        printf("Nome: %s", usuarios[i].nome);
        printf("Curso: %s", usuarios[i].curso);
        printf("Telefone: %s", usuarios[i].telefone);
        printf("Data de cadastro: %02d/%02d/%04d\n",
               usuarios[i].dataCadastro.dia,
               usuarios[i].dataCadastro.mes,
               usuarios[i].dataCadastro.ano
        );
    }
}