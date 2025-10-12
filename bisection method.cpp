#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x*x*x - x - 2);
}

float midpoint(float x1, float x2) {
    return ((x1 + x2) / 2);
}

int main() {
    float x1, x2, x3, f1, f2, f3, e;

    printf("Enter initial guesses: ");
    scanf("%f %f", &x1, &x2);

    printf("Enter allowable error: ");
    scanf("%f", &e);

    f1 = f(x1);
    f2 = f(x2);

    if (f1 * f2 > 0) {
        printf("Unable to bracket the root\n");
        return 0;
    }

    printf("----------------------------------------------------------------------------\n");
    printf("Iter\tx1\t\tx2\t\tx3\t\tf(x1)\t\tf(x2)\t\tf(x3)\n");
    printf("----------------------------------------------------------------------------\n");

    int iter = 1;
    do {
        x3 = midpoint(x1, x2);
        f3 = f(x3);

        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", iter, x1, x2, x3, f1, f2, f3);

        if (fabs(f3) < e) {
            printf("Root = %.6f\n", x3);
            break;
        }

        if (f1 * f3 < 0) {
            x2 = x3;
            f2 = f3;
        } else {
            x1 = x3;
            f1 = f3;
        }
        iter++;
    } while (1);

    return
    0;
}


