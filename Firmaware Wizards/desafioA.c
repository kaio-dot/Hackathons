#include <stdio.h>
#include <string.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char palavra[21];  
        scanf("%s", palavra);  
        
        if (strncmp(palavra, "OB", 2) == 0 && strlen(palavra) == 3 && palavra[2] != 'I') {
            printf("OBI"); 
        }
        else if (strncmp(palavra, "UR", 2) == 0 && strlen(palavra) == 3 && palavra[2] != 'I') {
            printf("URI");  
        }
        else {
            printf("%s", palavra);
        }
        if (i < N - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

