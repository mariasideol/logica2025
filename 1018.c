#include <stdio.h>
 
int main() {
    int valor, notas;
    
    scanf("%d", &valor);
    
    printf("%d\n", valor);
    
    notas = valor / 100;
    printf("%d nota(s) de R$ 100,00\n", notas);
    valor = valor % 100;
    
    notas = valor / 50;
    printf("%d nota(s) de R$ 50,00\n", notas);
    valor = valor % 50;
    
    notas = valor / 20;
    printf("%d nota(s) de R$ 20,00\n", notas);
    valor = valor % 20;
    
    notas = valor / 10;
    printf("%d nota(s) de R$ 10,00\n", notas);
    valor = valor % 10;
    
    notas = valor / 5;
    printf("%d nota(s) de R$ 5,00\n", notas);
    valor = valor % 5;
    
    notas = valor / 2;
    printf("%d nota(s) de R$ 2,00\n", notas);
    valor = valor % 2;
    
    notas = valor / 1;
    printf("%d nota(s) de R$ 1,00\n", notas);
    
    return 0;
}
