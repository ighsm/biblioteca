#ifndef MODELS_H
#define MODELS_H

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int codigo;
    char titulo[100];
    char autor[80];
    char editora[60];
    int ano;
    int exemplares;
    int status;
    int emprestimosRealizados;
} Livro;

typedef struct {
    int matricula;
    char nome[100];
    char curso[50];
    char telefone[15];
    Data dataCadastro;
} Usuario;

typedef struct {
    int codigo;
    int matricula;
    int codigoLivro;
    Data dataEmprestimo;        // ← obrigatório
    Data dataPrevDevolucao;     // ← obrigatório
    int status;                 // 0 = ativo, 1 = devolvido
} Emprestimo;

#endif