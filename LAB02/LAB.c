#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double series_sum_n(double x, int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i) * pow(2 * x, 2 * i) / factorial(2 * i);
    }
    return sum;
}

double series_sum_epsilon(double x, double epsilon) {
    double sum = 0, term;
    int n = 1;
    do {
        term = pow(-1, n) * pow(2 * x, 2 * n) / factorial(2 * n);
        sum += term;
        n++;
    } while (fabs(term) >= epsilon);
    return sum;
}

int main() {
    double a = 0.0, b = 1.0;
    int k = 5;
    double epsilon = 0.0001;
    int n = 5;

    double h = (b - a) / (k - 1);
    printf("x\tExact\tSeries(n=%d)\tSeries(epsilon=%.4f)\n", n, epsilon);

    for (int i = 0; i < k; i++) {
        double x = a + i * h;
        double exact_value = 2 * (cos(x) * cos(x) - 1);
        double sum_n = series_sum_n(x, n);
        double sum_epsilon = series_sum_epsilon(x, epsilon);
        printf("%.4f\t%.4f\t%.4f\t\t%.4f\n", x, exact_value, sum_n, sum_epsilon);
    }

    return 0;
}
