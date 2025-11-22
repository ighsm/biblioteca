#ifndef MODELS_H
#define MODELS_H

typedef struct {
    int codigo;
    char titulo[100];
    char autor[80];
    char editora[60];
    int ano;
    int exemplares;
    int status;
} Livro;

typedef struct {
    int matricula;
    char nome[100];
    char curso[50];
    char telefone[15];
    int dia, mes, ano;
} Usuario;

typedef struct {
    int codigo;
    int matricula;
    int codigoLivro;
    int diaEmp, mesEmp, anoEmp;
    int diaDev, mesDev, anoDev;
    int status; // 0 = livro não foi devolvido / 1 = devolvido
} Emprestimo;

#endif