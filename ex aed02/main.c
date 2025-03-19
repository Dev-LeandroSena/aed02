#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[30];
    char dt_nascimento[9];
    char curso[20];
    int turma;
    float nota1;
    float nota2;
    float media;
} Aluno;

void cadastrarAluno(Aluno *aluno, char opcao);
void imprimirAluno(Aluno aluno, char opcao);


int main() {
    setlocale(LC_ALL, "Portuguese");

    Aluno aluno1, aluno2;

    Aluno *ptrAluno1 = &aluno1;
    Aluno *ptrAluno2 = &aluno2;


    printf("Cadastro do primeiro aluno:\n");
    cadastrarAluno(ptrAluno1, 'A');

    printf("\nCadastro do segundo aluno:\n");
    cadastrarAluno(ptrAluno2, 'B');


    printf("\nDados do primeiro aluno:\n");
    imprimirAluno(aluno1, 'A');

    printf("\nDados do segundo aluno:\n");
    imprimirAluno(aluno2, 'B');

    return 0;
}


void cadastrarAluno(Aluno *aluno, char opcao) {
    printf("Digite a matrícula: ");
    scanf("%d", &aluno->matricula);
    getchar();


    printf("Digite o nome: ");
    fgets(aluno->nome, 30, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = 0;

    printf("Digite a data de nascimento (dd/mm/aa): ");
    scanf("%s", aluno->dt_nascimento);

    printf("Digite o curso: ");
    getchar();
    fgets(aluno->curso, 20, stdin);
    aluno->curso[strcspn(aluno->curso, "\n")] = 0;

    printf("Digite a turma: ");
    scanf("%d", &aluno->turma);

    printf("Digite a primeira nota: ");
    scanf("%f", &aluno->nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &aluno->nota2);

    aluno->media = (aluno->nota1 + aluno->nota2) / 2.0;
}


void imprimirAluno(Aluno aluno, char opcao) {
    printf("Matrícula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Data de Nascimento: %s\n", aluno.dt_nascimento);
    printf("Curso: %s\n", aluno.curso);
    printf("Turma: %d\n", aluno.turma);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Média: %.2f\n", aluno.media);
}
