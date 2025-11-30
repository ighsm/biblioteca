#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "dados.h"

void carregarTudo();      // carrega usuários, livros e empréstimos
void salvarTudo();        // salva tudo e faz backup
int carregarUsuarios(const char *path);
int salvarUsuarios(const char *path);
int carregarLivros(const char *path);
int salvarLivros(const char *path);
int carregarEmprestimos(const char *path);
int salvarEmprestimos(const char *path);
int backupArquivo(const char *origemPath);

#endif