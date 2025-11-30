#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dados.h"
#include "relatorios.h"

int dataMenor(Data d1, Data d2) {
    if (d1.ano != d2.ano) return d1.ano < d2.ano;
    if (d1.mes != d2.mes) return d1.mes < d2.mes;
    return d1.dia < d2.dia;
}

void relatorioLivrosMaisEmprestados() {
    printf("\n=== LIVROS MAIS EMPRESTADOS ===\n");

    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int idx[MAX_LIVROS];
    for (int i = 0; i < totalLivros; i++)
        idx[i] = i;

    for (int i = 0; i < totalLivros - 1; i++) {
        for (int j = i + 1; j < totalLivros; j++) {
            if (livros[idx[j]].emprestimosRealizados > livros[idx[i]].emprestimosRealizados) {
                int aux = idx[i];
                idx[i] = idx[j];
                idx[j] = aux;
            }
        }
    }

    for (int k = 0; k < totalLivros; k++) {
        printf("%s — %d emprestimos\n",
            livros[idx[k]].titulo,
            livros[idx[k]].emprestimosRealizados);
    }
}

void relatorioUsuariosAtrasados() {
    printf("\n=== USUARIOS COM ATRASO ===\n");

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    Data hoje;
    hoje.dia = tm->tm_mday;
    hoje.mes = tm->tm_mon + 1;
    hoje.ano = tm->tm_year + 1900;

    int achou = 0;

    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].status == 0 &&
            dataMenor(emprestimos[i].dataPrevDevolucao, hoje)) {

            printf("Matricula: %d — Livro: %d — Prevista: %02d/%02d/%04d\n",
                emprestimos[i].matricula,
                emprestimos[i].codigoLivro,
                emprestimos[i].dataPrevDevolucao.dia,
                emprestimos[i].dataPrevDevolucao.mes,
                emprestimos[i].dataPrevDevolucao.ano
            );
            achou = 1;
        }
    }

    if (!achou)
        printf("Nenhum atraso encontrado.\n");
}

void buscaAvancadaLivros() {
    char titulo[100], autor[100], editora[100];
    int ano;

    printf("\n=== BUSCA AVANCADA DE LIVROS ===\n");

    printf("Titulo (ou vazio): ");
    fflush(stdin);
    fgets(titulo, 100, stdin);
    titulo[strcspn(titulo, "\n")] = 0;

    printf("Autor (ou vazio): ");
    fflush(stdin);
    fgets(autor, 100, stdin);
    autor[strcspn(autor, "\n")] = 0;

    printf("Editora (ou vazio): ");
    fflush(stdin);
    fgets(editora, 100, stdin);
    editora[strcspn(editora, "\n")] = 0;

    printf("Ano (0 = ignorar): ");
    scanf("%d", &ano);

    int achou = 0;

    for (int i = 0; i < totalLivros; i++) {
        int ok = 1;

        if (strlen(titulo) > 0 && strstr(livros[i].titulo, titulo) == NULL) ok = 0;
        if (strlen(autor) > 0 && strstr(livros[i].autor, autor) == NULL) ok = 0;
        if (strlen(editora) > 0 && strstr(livros[i].editora, editora) == NULL) ok = 0;
        if (ano != 0 && livros[i].ano != ano) ok = 0;

        if (ok) {
            printf("\n[%d] %s — %s (%d)\n",
                livros[i].codigo,
                livros[i].titulo,
                livros[i].autor,
                livros[i].ano
            );
            achou = 1;
        }
    }

    if (!achou)
        printf("Nenhum livro encontrado com esses criterios.\n");
}