#ifndef DADOS_H
#define DADOS_H
#define MAX_LIVROS 500
#define MAX_EMPRESTIMOS 1000
#include "models.h"

// Vetores 
extern Usuario usuarios[100];
extern Livro livros[100];
extern Emprestimo emprestimos[100];

// Contadores
extern int totalUsuarios;
extern int totalLivros;
extern int totalEmprestimos;

#endif