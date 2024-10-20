#include <stdio.h>

int main() {
    int N;
    int numeros[1000];
    int cont2=0, cont3=0, cont4=0, cont5=0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
        
        if (numeros[i] % 2 == 0) cont2++;
        if (numeros[i] % 3 == 0) cont3++;
        if (numeros[i] % 4 == 0) cont4++;
        if (numeros[i] % 5 == 0) cont5++;
    }

    printf("%d Multiplo(s) de 2\n", cont2);
    printf("%d Multiplo(s) de 3\n", cont3);
    printf("%d Multiplo(s) de 4\n", cont4);
    printf("%d Multiplo(s) de 5\n", cont5);

    return 0;
}
