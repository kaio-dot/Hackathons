#include <stdio.h>
 
int main() {
 int idadeMonica, idadeF1, idadeF2, idadeF3;
 
 scanf("%d", &idadeMonica);
 scanf("%d", &idadeF1);
 scanf("%d", &idadeF2);
 
 idadeF3 = idadeMonica-(idadeF1+idadeF2);
 
    if(idadeF3>idadeF1 && idadeF3>idadeF2){
        printf("%d\n", idadeF3);
    }
    else if(idadeF2>idadeF3 && idadeF2>idadeF1){
        printf("%d\n", idadeF2);
    }
    else if(idadeF1>idadeF3 && idadeF1>idadeF2){
        printf("%d\n", idadeF1);
    }
 
    return 0;
}
