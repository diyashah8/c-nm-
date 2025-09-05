#include <stdio.h>
#include <math.h>

// Function f(x) = x*cos(x) - x*x
float f(float x) {
    return x * cos(x) - x * x;
}

// Derivative f'(x) = cos(x) - x*sin(x) - 2*x
float df(float x) {
    return cos(x) - x * sin(x) - 2 * x;
}

// Error calculation
float error(float x1, float x2) {
    return fabs((x2 - x1) / x2);
}

// Newton-Raphson iteration
float root(float x1) {
    return (x1 - (f(x1) / df(x1)));
}

int main() {
    float x1, x2, E, Ear;
    int i = 1;

    printf("Enter an initial guess: ");
    scanf("%f", &x1);

    printf("Enter the precise error to be considered: ");
    scanf("%f", &E);

    printf("It\tX(i)\t\tf(xi)\t\tf'(xi)\t\tXi+1\t\tError\n");

    do {
        x2 = root(x1);

        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\n", 
               i, x1, f(x1), df(x1), x2);

        Ear = error(x1, x2);
        x1 = x2;
        i++;
    } while (Ear > E);

    printf("\nThe final root = %.6f\n", x2);

    return 0;
}

