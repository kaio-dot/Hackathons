#include <stdio.h>
#include <string.h>

#define MAX_ARQUIVOS 1000

typedef struct {
    char nome[50];
    int tamanho; 
} Arquivo;

Arquivo disco[MAX_ARQUIVOS]; 
int tamanhoDiscoKb = 0;
int espacoUsado = 0;
int totalArquivos = 0;
int erro = 0; 

int converterParaKb(int tamanho, char *unidade) {
    if (strcmp(unidade, "Gb") == 0)
        return tamanho * 1024 * 1024;
    else if (strcmp(unidade, "Mb") == 0)
        return tamanho * 1024;
    else
        return tamanho; 
}

void inserirArquivo(char *nome, int tamanho, char *unidade) {
    int tamanhoKb = converterParaKb(tamanho, unidade);

    if (espacoUsado + tamanhoKb > tamanhoDiscoKb) {
        printf("ERRO: disco cheio\n");
        erro = 1; 
        return;
    }

    strcpy(disco[totalArquivos].nome, nome);
    disco[totalArquivos].tamanho = tamanhoKb;
    totalArquivos++;
    espacoUsado += tamanhoKb;
}

void removerArquivo(char *nome) {
    for (int i = 0; i < totalArquivos; i++) {
        if (strcmp(disco[i].nome, nome) == 0) {
            espacoUsado -= disco[i].tamanho;
            disco[i] = disco[totalArquivos - 1];  
            totalArquivos--;
            return;
        }
    }
}

void otimizarDisco() {
    // A otimização pode ser apenas organizar os arquivos, o que, na simulação, já ocorre automaticamente.
    // Portanto, essa função não precisa fazer nada específico no momento.
}

void mostrarEstadoDoDisco() {
    int espacoPorBloco = tamanhoDiscoKb / 8; 
    int blocos[8] = {0}; 
    int espacoLivre = tamanhoDiscoKb - espacoUsado;

    for (int i = 0; i < 8; i++) {
        int espacoBloco = espacoPorBloco * (i + 1);
        if (espacoUsado >= espacoBloco) {
            blocos[i] = 100;
        } else if (espacoUsado >= espacoBloco - espacoPorBloco) {
            blocos[i] = (espacoUsado - (espacoBloco - espacoPorBloco)) * 100 / espacoPorBloco;
        }
    }

    for (int i = 0; i < 8; i++) {
        if (blocos[i] > 75) {
            printf("[#]");
        } else if (blocos[i] > 25) {
            printf("[-]");
        } else {
            printf("[ ]");
        }
    }
    printf("\n");
}

int main() {
    int N;
    char unidade[3], operacao[10], nomeArquivo[50];
    int tamanho;

    do {
        scanf("%d", &N); 
        if (N == 0)
            break;

        scanf("%d %s", &tamanhoDiscoKb, unidade);
        tamanhoDiscoKb = converterParaKb(tamanhoDiscoKb, unidade);
        espacoUsado = 0; 
        totalArquivos = 0;
        erro = 0; 

        for (int i = 0; i < N; i++) {
            scanf("%s", operacao);

            if (strcmp(operacao, "insere") == 0) {
                scanf("%s %d %s", nomeArquivo, &tamanho, unidade);
                inserirArquivo(nomeArquivo, tamanho, unidade);
            } else if (strcmp(operacao, "remove") == 0) {
                scanf("%s", nomeArquivo);
                removerArquivo(nomeArquivo);
            } else if (strcmp(operacao, "otimiza") == 0) {
                otimizarDisco();
            }
        }

        if (!erro) {
            mostrarEstadoDoDisco(); 
        }
    } while (N != 0);  // O loop continua enquanto N for diferente de 0

    return 0;
}
