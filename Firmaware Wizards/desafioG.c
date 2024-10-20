#include <stdio.h>

int main() {
    int P, N, C;

    while (scanf("%d %d %d", &P, &N, &C) && (P != 0 || N != 0 || C != 0)) {
        int experimento[N][P];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                scanf("%d", &experimento[i][j]);
            }
        }

        int total_palitos = 0;

        for (int j = 0; j < P; j++) {
            int comprimento_palito = 0;

            for (int i = 0; i < N; i++) {
                if (experimento[i][j] == 1) {
                    comprimento_palito++;
                } else {
                    if (comprimento_palito >= C) {
                        total_palitos++;
                    }
                    comprimento_palito = 0; 
                }
            }
            if (comprimento_palito >= C) {
                total_palitos++;
            }
        }
        printf("%d\n", total_palitos);
    }

    return 0;
}
