#include "models.h"

// Tamanhos máximos
#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 100

// Vetores globais
Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

// Contadores
int totalLivros = 0;
int totalUsuarios = 0;
int totalEmprestimos = 0;