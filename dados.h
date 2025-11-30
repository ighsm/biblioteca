#ifndef DADOS_H
#define DADOS_H

#include "models.h"

#define MAX_USUARIOS 500
#define MAX_LIVROS 500
#define MAX_EMPRESTIMOS 1000

extern Usuario usuarios[MAX_USUARIOS];
extern Livro livros[MAX_LIVROS];
extern Emprestimo emprestimos[MAX_EMPRESTIMOS];

extern int totalUsuarios;
extern int totalLivros;
extern int totalEmprestimos;

#endif