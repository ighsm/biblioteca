#include <stdio.h>
#include <string.h>
#include "dados.h"
#include "funcoesEmprestimos.h"

// Função para limpar buffer
static void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Adiciona 7 dias automaticamente
void somar7Dias(Data *d) {
    d->dia += 7;

    // ajuste simples de mês
    if (d->dia > 30) {
        d->dia -= 30;
        d->mes++;

        if (d->mes > 12) {
            d->mes = 1;
            d->ano++;
        }
    }
}

void realizarEmprestimo() {
    if (totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite maximo de emprestimos atingido.\n");
        return;
    }

    int matricula, codigoLivro;

    printf("\n--- REALIZAR EMPRESTIMO ---\n");

    printf("Matricula do usuario: ");
    scanf("%d", &matricula);

    // Buscar usuário
    int idxUser = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].matricula == matricula) {
            idxUser = i;
            break;
        }
    }
    if (idxUser == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    printf("Codigo do livro: ");
    scanf("%d", &codigoLivro);

    // Buscar livro
    int idxLivro = -1;
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigoLivro) {
            idxLivro = i;
            break;
        }
    }
    if (idxLivro == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    // Verificar disponibilidade
    if (livros[idxLivro].exemplares <= 0) {
        printf("Nao ha exemplares disponiveis.\n");
        return;
    }

    // Registrar empréstimo
    Emprestimo *e = &emprestimos[totalEmprestimos];

    e->codigo = totalEmprestimos + 1; 
    e->matricula = matricula;
    e->codigoLivro = codigoLivro;

    printf("Dia do emprestimo: ");
    scanf("%d", &e->dataEmprestimo.dia);
    printf("Mes: ");
    scanf("%d", &e->dataEmprestimo.mes);
    printf("Ano: ");
    scanf("%d", &e->dataEmprestimo.ano);

    e->dataPrevDevolucao = e->dataEmprestimo;
    somar7Dias(&e->dataPrevDevolucao);

    e->status = 0; // ativo

    // Atualizar livro
    livros[idxLivro].exemplares--;
    livros[idxLivro].emprestimosRealizados++;

    totalEmprestimos++;

    printf("\nEmprestimo realizado com sucesso!\n");
}

void realizarDevolucao() {
    int cod;
    printf("\n--- DEVOLUCAO ---\n");
    printf("Codigo do emprestimo: ");
    scanf("%d", &cod);

    int idx = -1;
    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].codigo == cod && emprestimos[i].status == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Emprestimo nao encontrado ou ja devolvido.\n");
        return;
    }

    emprestimos[idx].status = 1; // devolvido

    // devolve exemplar
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == emprestimos[idx].codigoLivro) {
            livros[i].exemplares++;
            break;
        }
    }

    printf("Devolucao realizada!\n");
}

void renovarEmprestimo() {
    int cod;

    printf("\n--- RENOVAR EMPRESTIMO ---\n");
    printf("Codigo do emprestimo: ");
    scanf("%d", &cod);

    int idx = -1;
    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].codigo == cod && emprestimos[i].status == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Emprestimo nao encontrado ou ja devolvido.\n");
        return;
    }

    somar7Dias(&emprestimos[idx].dataPrevDevolucao);

    printf("Emprestimo renovado por +7 dias!\n");
}

void listarEmprestimosAtivos() {
    printf("\n--- EMPRESTIMOS ATIVOS ---\n");

    int encontrou = 0;

    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].status == 0) {
            printf("Codigo: %d | Usuario: %d | Livro: %d | Prevista: %02d/%02d/%04d\n",
                emprestimos[i].codigo,
                emprestimos[i].matricula,
                emprestimos[i].codigoLivro,
                emprestimos[i].dataPrevDevolucao.dia,
                emprestimos[i].dataPrevDevolucao.mes,
                emprestimos[i].dataPrevDevolucao.ano
            );
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum emprestimo ativo.\n");
    }
}