#include <stdio.h>
#include <math.h>

typedef struct {
    double a3, a2, a1, a0;
} third_order_polynomial;

typedef struct {
    double a3, a2, a1, a0;
    double value;
} polynomial;

double evaluate_polynomial(third_order_polynomial p, double x) {
    return p.a3*x*x*x + p.a2*x*x + p.a1*x + p.a0;
}

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b) {
    polynomial result;

    result.a3 = (p1.a3 * p2.a3) / 4.0;
    result.a2 = (p1.a2 * p2.a3 + p1.a3 * p2.a2) / 3.0;
    result.a1 = (p1.a1 * p2.a3 + p1.a2 * p2.a2 + p1.a3 * p2.a1) / 2.0;
    result.a0 = (p1.a0 * p2.a3 + p1.a1 * p2.a2 + p1.a2 * p2.a1 + p1.a3 * p2.a0);

    double integral_b = result.a3*pow(b,4)/4.0 + result.a2*pow(b,3)/3.0 + result.a1*pow(b,2)/2.0 + result.a0*b;
    double integral_a = result.a3*pow(a,4)/4.0 + result.a2*pow(a,3)/3.0 + result.a1*pow(a,2)/2.0 + result.a0*a;
    result.value = integral_b - integral_a;

    return result;
}

int main() {
    third_order_polynomial p1, p2;
    double a, b;
    printf("Enter coefficients of first polinom: (a3, a2, a1, a0): ");
    scanf("%lf %lf %lf %lf", &p1.a3, &p1.a2, &p1.a1, &p1.a0);
    printf("Enter coefficients of second polinom (a3, a2, a1, a0): ");
    scanf("%lf %lf %lf %lf", &p2.a3, &p2.a2, &p2.a1, &p2.a0);
    printf("Enter interval (a, b): ");
    scanf("%lf %lf", &a, &b);
    polynomial integral = get_integral(p1, p2, a, b);
    printf("Integrated polynomial: %.2fx^3 + %.2fx^2 + %.2fx + %.2f\n", integral.a3, integral.a2, integral.a1, integral.a0);
    printf("Value of integrated polynomial between [%.1lf, %.1lf]: %.2f\n", a, b, integral.value);

    return 0;
}
