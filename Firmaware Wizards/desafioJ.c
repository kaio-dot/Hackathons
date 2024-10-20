#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void calcular_tempo_minimo() {
    int N; 
    while (scanf("%d", &N) != EOF) {
        int e1, e2;
        scanf("%d %d", &e1, &e2); 
        
        int *a1 = (int *)malloc(N * sizeof(int)); 
        int *a2 = (int *)malloc(N * sizeof(int)); 
        int *t1 = (int *)malloc((N - 1) * sizeof(int)); 
        int *t2 = (int *)malloc((N - 1) * sizeof(int));
      
        for (int i = 0; i < N; i++) {
            scanf("%d", &a1[i]);
        }
   
        for (int i = 0; i < N; i++) {
            scanf("%d", &a2[i]);
        }
  
        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &t1[i]);
        }
        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &t2[i]);
        }
        
        int x1, x2; 
        scanf("%d %d", &x1, &x2);

        int T1[N], T2[N];
        T1[0] = e1 + a1[0];
        T2[0] = e2 + a2[0];
        
        for (int i = 1; i < N; i++) {
            T1[i] = T2[i] = INT_MAX; 
            
            T1[i] = (T1[i-1] + a1[i] < T1[i]) ? T1[i-1] + a1[i] : T1[i];
            T1[i] = (T2[i-1] + t2[i-1] + a1[i] < T1[i]) ? T2[i-1] + t2[i-1] + a1[i] : T1[i];

            T2[i] = (T2[i-1] + a2[i] < T2[i]) ? T2[i-1] + a2[i] : T2[i];
            T2[i] = (T1[i-1] + t1[i-1] + a2[i] < T2[i]) ? T1[i-1] + t1[i-1] + a2[i] : T2[i];
        }
        
        int tempo_minimo = (T1[N-1] + x1 < T2[N-1] + x2) ? T1[N-1] + x1 : T2[N-1] + x2;

        printf("%d\n", tempo_minimo);

        free(a1);
        free(a2);
        free(t1);
        free(t2);
    }
}

int main() {
    calcular_tempo_minimo();
    return 0;
}
