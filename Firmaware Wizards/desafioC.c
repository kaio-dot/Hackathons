#include <stdio.h>
 
int main() {
 
    int N, num1, num2;
    char operacao;
    
    scanf("%d", &N);
    scanf("%d %c %d", &num1, &operacao, &num2);
    
    if(operacao=='+'){
        int soma=num1+num2;
            if(soma>N){
                printf("OVERFLOW\n");
            }
            else{
                printf("OK\n");
            }
    }
    else if(operacao=='*'){
        int mult=num1*num2;
            if(mult>N){
                 printf("OVERFLOW\n");
            }
            else{
                printf("OK\n");
            }
    }
    
 
    return 0;
}
