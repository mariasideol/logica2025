#include <stdio.h>

int main() {
    char name[100];
    double salary, sales, total;

    scanf("%s", name);
    scanf("%lf", &salary);
    scanf("%lf", &sales);

    total = salary + (sales * 0.15);

    printf("TOTAL = R$ %.2lf\n", total);

    return 0;
}
