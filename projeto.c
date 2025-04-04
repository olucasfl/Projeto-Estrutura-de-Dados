#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 60

typedef struct Disciplina {
    char nome[50];
    struct Disciplina *prox;
} Disciplina;

typedef struct {
    int rgm;
    Disciplina *disciplinas;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

void inserirAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("\nLimite de alunos atingido!\n");
        return;
    }

    Aluno novo;
    printf("\nDigite o RGM do aluno: ");
    scanf("%d", &novo.rgm);
    novo.disciplinas = NULL;

    int i = totalAlunos - 1;
    while (i >= 0 && alunos[i].rgm > novo.rgm) {
        alunos[i + 1] = alunos[i];
        i--;
    }
    alunos[i + 1] = novo;
    totalAlunos++;

    char resposta;
    do {
        Disciplina *novaDisc = (Disciplina *)malloc(sizeof(Disciplina));
        if (!novaDisc) {
            printf("Erro de alocação de memória!\n");
            return;
        }
        printf("Digite o nome da disciplina: ");
        scanf(" %[^\n]", novaDisc->nome);
        novaDisc->prox = alunos[i + 1].disciplinas;
        alunos[i + 1].disciplinas = novaDisc;
        
        printf("Mais disciplina? (s/n): ");
        scanf(" %c", &resposta);
    } while (resposta == 's' || resposta == 'S');
}

int main() {
    int opcao;
    do {
        printf("\nMENU:\n");
        printf("1 - Incluir Aluno\n");
        printf("2 - Mostrar Alunos\n");
        printf("3 - Buscar Aluno\n");
        printf("4 - Remover Aluno\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirAluno();
                break;
            case 2:
            // mostrar alunos
                break;
            case 3:
            // buscar aluno
                break;
            case 4:
            // remover aluno
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}