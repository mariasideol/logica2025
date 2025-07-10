#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897
 
int main() {
    double a, b, c;
    
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        double s = (a + b + c) / 2.0;
        
        // Área do triângulo (Heron)
        double area_triangle = sqrt(s * (s - a) * (s - b) * (s - c));
        
        // Raio do círculo inscrito
        double r_in = area_triangle / s;
        double area_roses = PI * r_in * r_in;

        // Raio do círculo circunscrito
        double r_out = (a * b * c) / (4.0 * area_triangle);
        double area_sunflowers = PI * r_out * r_out - area_triangle;

        // Área das violetas (dentro do triângulo, mas fora do círculo inscrito)
        double area_violets = area_triangle - area_roses;

        // Impressão com 4 casas decimais
        printf("%.4lf %.4lf %.4lf\n", area_sunflowers, area_violets, area_roses);
    }
 
    return 0;
}
