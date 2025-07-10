#include <stdio.h>

int main() {
    int number, hours;
    float value_per_hour, salary;

    scanf("%d", &number);
    scanf("%d", &hours);
    scanf("%f", &value_per_hour);

    salary = hours * value_per_hour;

    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", salary);

    return 0;
}
