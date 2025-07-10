#include <stdio.h>
 
int main() {
    int codigo1, codigo2, quantidade1, quantidade2;
    double preco1, preco2, total;
    
    scanf("%d %d %lf", &codigo1, &quantidade1, &preco1);
    scanf("%d %d %lf", &codigo2, &quantidade2, &preco2);
    
    total = (quantidade1 * preco1) + (quantidade2 * preco2);
    
    printf("VALOR A PAGAR: R$ %.2lf\n", total);
 
    return 0;
}
