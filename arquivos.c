#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivos.h"
#include "dados.h"

/*
Formato dos arquivos (campo separado por '|')
- usuarios.txt
  matricula|nome|curso|telefone|dia/mes/ano\n

- livros.txt
  codigo|titulo|autor|editora|ano|exemplares|status|emprestimosRealizados\n

- emprestimos.txt
  codigo|matricula|codigoLivro|diaEmp/mesEmp/anoEmp|diaPrev/mesPrev/anoPrev|status\n
*/

static void remove_newline(char *s) {
    if (!s) return;
    size_t L = strlen(s);
    if (L == 0) return;
    if (s[L-1] == '\n') s[L-1] = '\0';
    if (L > 1 && s[L-2] == '\r') s[L-2] = '\0';
}

int carregarUsuarios(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return 0; // arquivo não existe ou não pôde abrir

    char linha[512];
    totalUsuarios = 0;
    while (fgets(linha, sizeof(linha), f) && totalUsuarios < MAX_USUARIOS) {
        remove_newline(linha);
        // dividir por '|'
        char *tok = strtok(linha, "|");
        if (!tok) continue;
        usuarios[totalUsuarios].matricula = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        strncpy(usuarios[totalUsuarios].nome, tok, sizeof(usuarios[totalUsuarios].nome)-1);
        usuarios[totalUsuarios].nome[sizeof(usuarios[totalUsuarios].nome)-1] = '\0';

        tok = strtok(NULL, "|"); if (!tok) continue;
        strncpy(usuarios[totalUsuarios].curso, tok, sizeof(usuarios[totalUsuarios].curso)-1);
        usuarios[totalUsuarios].curso[sizeof(usuarios[totalUsuarios].curso)-1] = '\0';

        tok = strtok(NULL, "|"); if (!tok) continue;
        strncpy(usuarios[totalUsuarios].telefone, tok, sizeof(usuarios[totalUsuarios].telefone)-1);
        usuarios[totalUsuarios].telefone[sizeof(usuarios[totalUsuarios].telefone)-1] = '\0';

        tok = strtok(NULL, "|"); if (!tok) continue;
        int d=0,m=0,a=0;
        sscanf(tok, "%d/%d/%d", &d, &m, &a);
        usuarios[totalUsuarios].dataCadastro.dia = d;
        usuarios[totalUsuarios].dataCadastro.mes = m;
        usuarios[totalUsuarios].dataCadastro.ano = a;

        totalUsuarios++;
    }
    fclose(f);
    return 1;
}

int salvarUsuarios(const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) return 0;
    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(f, "%d|%s|%s|%s|%02d/%02d/%04d\n",
            usuarios[i].matricula,
            usuarios[i].nome,
            usuarios[i].curso,
            usuarios[i].telefone,
            usuarios[i].dataCadastro.dia,
            usuarios[i].dataCadastro.mes,
            usuarios[i].dataCadastro.ano
        );
    }
    fclose(f);
    return 1;
}

int carregarLivros(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    char linha[1024];
    totalLivros = 0;
    while (fgets(linha, sizeof(linha), f) && totalLivros < MAX_LIVROS) {
        remove_newline(linha);
        char *tok = strtok(linha, "|");
        if (!tok) continue;
        livros[totalLivros].codigo = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        strncpy(livros[totalLivros].titulo, tok, sizeof(livros[totalLivros].titulo)-1);
        livros[totalLivros].titulo[sizeof(livros[totalLivros].titulo)-1] = '\0';

        tok = strtok(NULL, "|"); if (!tok) continue;
        strncpy(livros[totalLivros].autor, tok, sizeof(livros[totalLivros].autor)-1);
        livros[totalLivros].autor[sizeof(livros[totalLivros].autor)-1] = '\0';

        tok = strtok(NULL, "|"); if (!tok) continue;
        strncpy(livros[totalLivros].editora, tok, sizeof(livros[totalLivros].editora)-1);
        livros[totalLivros].editora[sizeof(livros[totalLivros].editora)-1] = '\0';

        tok = strtok(NULL, "|"); if (!tok) continue;
        livros[totalLivros].ano = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        livros[totalLivros].exemplares = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        livros[totalLivros].status = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) {
            livros[totalLivros].emprestimosRealizados = 0;
        } else {
            livros[totalLivros].emprestimosRealizados = atoi(tok);
        }

        totalLivros++;
    }
    fclose(f);
    return 1;
}

int salvarLivros(const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) return 0;
    for (int i = 0; i < totalLivros; i++) {
        fprintf(f, "%d|%s|%s|%s|%d|%d|%d|%d\n",
            livros[i].codigo,
            livros[i].titulo,
            livros[i].autor,
            livros[i].editora,
            livros[i].ano,
            livros[i].exemplares,
            livros[i].status,
            livros[i].emprestimosRealizados
        );
    }
    fclose(f);
    return 1;
}

int carregarEmprestimos(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    char linha[512];
    totalEmprestimos = 0;
    while (fgets(linha, sizeof(linha), f) && totalEmprestimos < MAX_EMPRESTIMOS) {
        remove_newline(linha);
        char *tok = strtok(linha, "|");
        if (!tok) continue;
        emprestimos[totalEmprestimos].codigo = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        emprestimos[totalEmprestimos].matricula = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        emprestimos[totalEmprestimos].codigoLivro = atoi(tok);

        tok = strtok(NULL, "|"); if (!tok) continue;
        sscanf(tok, "%d/%d/%d", 
            &emprestimos[totalEmprestimos].dataEmprestimo.dia,
            &emprestimos[totalEmprestimos].dataEmprestimo.mes,
            &emprestimos[totalEmprestimos].dataEmprestimo.ano);

        tok = strtok(NULL, "|"); if (!tok) continue;
        sscanf(tok, "%d/%d/%d", 
            &emprestimos[totalEmprestimos].dataPrevDevolucao.dia,
            &emprestimos[totalEmprestimos].dataPrevDevolucao.mes,
            &emprestimos[totalEmprestimos].dataPrevDevolucao.ano);

        tok = strtok(NULL, "|"); if (!tok) continue;
        emprestimos[totalEmprestimos].status = atoi(tok);

        totalEmprestimos++;
    }
    fclose(f);
    return 1;
}

int salvarEmprestimos(const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) return 0;
    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(f, "%d|%d|%d|%02d/%02d/%04d|%02d/%02d/%04d|%d\n",
            emprestimos[i].codigo,
            emprestimos[i].matricula,
            emprestimos[i].codigoLivro,
            emprestimos[i].dataEmprestimo.dia,
            emprestimos[i].dataEmprestimo.mes,
            emprestimos[i].dataEmprestimo.ano,
            emprestimos[i].dataPrevDevolucao.dia,
            emprestimos[i].dataPrevDevolucao.mes,
            emprestimos[i].dataPrevDevolucao.ano,
            emprestimos[i].status
        );
    }
    fclose(f);
    return 1;
}

/* cria backup do arquivo origemPath -> data/<nome>_YYYYmmdd_HHMMSS.bak */
int backupArquivo(const char *origemPath) {
    FILE *f = fopen(origemPath, "r");
    if (!f) return 0;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char nomeBackup[512];
    const char *base = strrchr(origemPath, '/');
    if (!base) base = strrchr(origemPath, '\\');
    if (base) base++; else base = origemPath;

    snprintf(nomeBackup, sizeof(nomeBackup), "data/%s_%04d%02d%02d_%02d%02d%02d.bak",
        base,
        tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);

    FILE *out = fopen(nomeBackup, "w");
    if (!out) { fclose(f); return 0; }

    char buf[1024];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), f)) > 0) {
        fwrite(buf, 1, n, out);
    }

    fclose(f);
    fclose(out);
    return 1;
}

/* Funções de conveniência para carregar/salvar tudo */
void carregarTudo() {
    // Crie a pasta data/ manualmente antes de usar, se necessário
    carregarUsuarios("data/usuarios.txt");
    carregarLivros("data/livros.txt");
    carregarEmprestimos("data/emprestimos.txt");
}

void salvarTudo() {
    // salvar e depois criar backup dos arquivos originais (se existirem)
    salvarUsuarios("data/usuarios.txt");
    backupArquivo("data/usuarios.txt");

    salvarLivros("data/livros.txt");
    backupArquivo("data/livros.txt");

    salvarEmprestimos("data/emprestimos.txt");
    backupArquivo("data/emprestimos.txt");
}