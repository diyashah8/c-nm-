#include <stdio.h>
#include <math.h>

float f(float x) {
    return x * x + log(x) - 3;
}

float root(float x1, float x2) {
    float x3;
    x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
    return x3;
}

int main() {
    float x1, x2, x3, E, Ear;
    int i = 1;

    printf("Enter the value of x1 and x2: ");
    scanf("%f %f", &x1, &x2);

    printf("Enter the value of the error: ");
    scanf("%f", &E);

    printf("\n i\t   x1\t\t   x2\t\t f(x1)\t\t f(x2)\t\t   x3\t\t   Ear");
    printf("\n-------------------------------------------------------------------------------");

    do {
        x3 = root(x1, x2);
        printf("\n%d\t%f\t%f\t%f\t%f\t%f\t%f", i, x1, x2, f(x1), f(x2), x3, Ear);

        x1 = x2;
        x2 = x3;

        if (x2 != 0) {
            Ear = fabs((x2 - x1) / x2);
        } else {
            Ear = fabs(x2 - x1);
            continue;
        }
        i++;
    } while (Ear > E);

    printf("\nThe root is %f\n", x3);
    return 0;
}

