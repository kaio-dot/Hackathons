#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMANDOS 100
#define MEMORIA_TAMANHO 100
#define PILHA_TAMANHO 100

int pilha[PILHA_TAMANHO];
int memoria[MEMORIA_TAMANHO];
int topo_pilha = -1;
int saida[MAX_COMANDOS];
int saida_topo = 0;

// Funções auxiliares para manipulação da pilha
void push(int valor) {
    if (topo_pilha < PILHA_TAMANHO - 1) {
        pilha[++topo_pilha] = valor;
    } else {
        printf("Erro: Pilha cheia!\n");
        exit(1);
    }
}

int pop() {
    if (topo_pilha >= 0) {
        return pilha[topo_pilha--];
    } else {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
}

// Função para processar os comandos
void emulador_maquina(int n, char comandos[][20]) {
    for (int i = 0; i < n; i++) {
        if (strncmp(comandos[i], "push_", 5) == 0) {
            char *valor_str = &comandos[i][5];
            if (valor_str[0] == 'R') {  // Acessar a memória
                int posicao = atoi(&valor_str[1]);
                push(memoria[posicao]);
            } else {  // Valor constante
                int valor = atoi(valor_str);
                push(valor);
            }
        } else if (strncmp(comandos[i], "pop_", 4) == 0) {
            int posicao = atoi(&comandos[i][5]);
            memoria[posicao] = pop();
        } else if (strcmp(comandos[i], "add") == 0) {
            int b = pop();
            int a = pop();
            push(a + b);
        } else if (strcmp(comandos[i], "mul") == 0) {
            int b = pop();
            int a = pop();
            push(a * b);
        } else if (strcmp(comandos[i], "div") == 0) {
            int b = pop();
            int a = pop();
            push(a / b);
        } else if (strcmp(comandos[i], "sub") == 0) {
            int b = pop();
            int a = pop();
            push(a - b);
        } else if (strcmp(comandos[i], "print") == 0) {
            saida[saida_topo++] = pop();
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char comandos[MAX_COMANDOS][20];
    
    // Ler os comandos
    for (int i = 0; i < n; i++) {
        scanf("%s", comandos[i]);
    }

    // Inicializar a memória com zero
    for (int i = 0; i < MEMORIA_TAMANHO; i++) {
        memoria[i] = 0;
    }

    // Executar o emulador
    emulador_maquina(n, comandos);

    // Imprimir a saída
    for (int i = 0; i < saida_topo; i++) {
        printf("%d\n", saida[i]);
    }

    return 0;
}
