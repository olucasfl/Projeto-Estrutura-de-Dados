#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 60

typedef struct disciplina {
    char nome[50];
    struct disciplina *prox;
} Disciplina;

typedef struct aluno {
    int RGM;
    Disciplina *disciplinas;
} Aluno;

Aluno listaAlunos[MAX_ALUNOS];
int quantidadeAlunos = 0;

void adicionarDisciplina(Aluno *aluno) {
    char resposta;
    do {
        Disciplina *nova = (Disciplina*)malloc(sizeof(Disciplina));
        if (nova == NULL) {
            printf("Erro ao alocar memória para a disciplina.\n");
            return;
        }

        printf("Nome da disciplina: ");
        getchar();
        fgets(nova->nome, sizeof(nova->nome), stdin);

        size_t len = strlen(nova->nome);
        if (len > 0 && nova->nome[len - 1] == '\n') {
            nova->nome[len - 1] = '\0';
        }

        nova->prox = NULL;

        if (aluno->disciplinas == NULL) {
            aluno->disciplinas = nova;
        } else {
            Disciplina *atual = aluno->disciplinas;
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = nova;
        }

        printf("Mais disciplinas? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');
}

void incluirAluno() {
    if (quantidadeAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    int rgm;
    printf("Digite o RGM do aluno: ");
    scanf("%d", &rgm);

    for (int i = 0; i < quantidadeAlunos; i++) {
        if (listaAlunos[i].RGM == rgm) {
            printf("RGM já cadastrado!\n");
            return;
        }
    }

    int posicao = 0;
    while (posicao < quantidadeAlunos && listaAlunos[posicao].RGM < rgm) {
        posicao++;
    }

    for (int i = quantidadeAlunos; i > posicao; i--) {
        listaAlunos[i] = listaAlunos[i-1];
    }

    listaAlunos[posicao].RGM = rgm;
    listaAlunos[posicao].disciplinas = NULL;

    adicionarDisciplina(&listaAlunos[posicao]);

    quantidadeAlunos++;
    printf("Aluno cadastrado com sucesso!\n");
}

void mostrarTodos() {
    if (quantidadeAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE ALUNOS ---\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("RGM: %d\n", listaAlunos[i].RGM);
        printf("Disciplinas:\n");
        Disciplina *atual = listaAlunos[i].disciplinas;
        while (atual != NULL) {
            printf("  - %s\n", atual->nome);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int buscarPorRGM(int rgm) {
    int inicio = 0;
    int fim = quantidadeAlunos - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (listaAlunos[meio].RGM == rgm) {
            return meio;
        } else if (listaAlunos[meio].RGM < rgm) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void procurarAluno() {
    int rgm;
    printf("Digite o RGM a buscar: ");
    scanf("%d", &rgm);

    int pos = buscarPorRGM(rgm);
    if (pos == -1) {
        printf("Aluno não encontrado!\n");
    } else {
        printf("\nRGM: %d\n", listaAlunos[pos].RGM);
        printf("Disciplinas:\n");
        Disciplina *atual = listaAlunos[pos].disciplinas;
        while (atual != NULL) {
            printf("  - %s\n", atual->nome);
            atual = atual->prox;
        }
    }
}

void removerAluno() {
    int rgm;
    printf("Digite o RGM a remover: ");
    scanf("%d", &rgm);

    int pos = buscarPorRGM(rgm);
    if (pos == -1) {
        printf("Aluno não encontrado!\n");
        return;
    }

    Disciplina *atual = listaAlunos[pos].disciplinas;
    while (atual != NULL) {
        Disciplina *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    for (int i = pos; i < quantidadeAlunos - 1; i++) {
        listaAlunos[i] = listaAlunos[i+1];
    }

    quantidadeAlunos--;
    printf("Aluno removido com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Incluir aluno\n");
        printf("2. Mostrar todos\n");
        printf("3. Procurar aluno\n");
        printf("4. Remover aluno\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                incluirAluno();
                break;
            case 2:
                mostrarTodos();
                break;
            case 3:
                procurarAluno();
                break;
            case 4:
                removerAluno();
                break;
            case 5:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    // Liberando memória
    for (int i = 0; i < quantidadeAlunos; i++) {
        Disciplina *atual = listaAlunos[i].disciplinas;
        while (atual != NULL) {
            Disciplina *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    return 0;
}
