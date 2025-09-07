#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x - 4*x - 9;
}

float root(float x1, float x2) {
    float x3;
    x3 = x2 - ((f(x2) * (x2 - x1)) / (f(x2) - f(x1)));
    return x3;
}

int main() {
    float x1, x2, E, Ear, x3;
    int i = 1;

    printf("Enter the value of x1 and x2: ");
    scanf("%f %f", &x1, &x2);

    printf("Enter the value of the error: ");
    scanf("%f", &E);

    printf("\nIter\tx1\t\tx2\t\tf(x1)\t\tf(x2)\t\tx3\t\tEar\n");
    printf("----------------------------------------------------------------\n");

    do {
        x3 = root(x1, x2);
        printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, x1, x2, f(x1), f(x2), x3, Ear);

        x1 = x2;
        x2 = x3;

        Ear = fabs((x2 - x1) / x2);
        i++;
    } while (Ear > E);

    printf("\nThe root is %f\n", x3);
    return 0;
}

