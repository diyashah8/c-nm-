#include <stdio.h>
#include <math.h>

float f(float x) {
    return log(x) - cos(x);
}

float df(float x) {
    return (1/x) + sin(x);
}

float error(float x1, float x2) {
    return fabs((x2 - x1) / x2);
}

float root(float x1) {
    return (x1 - (f(x1) / df(x1)));
}

int main() {
    float x1, x2, E, Ear;
    int i = 1;
    
    printf("Enter a initial guess: ");
    scanf("%f", &x1);
    printf("Enter the precise error to be considered: ");
    scanf("%f", &E);
    
    printf("Itr(i)\tx1\t\tf(x1)\t\tdf(x1)\t\tx2\t\tError");
    
    do {
        x2 = root(x1);
        printf("\n%d\t%f\t%f\t%f\t%f", i, x1, f(x1), df(x1), x2);
        Ear = error(x1, x2);
        x1 = x2;
        i++;
    } while(Ear > E);
    
    printf("\nThe final root = %f", x2);
    
    return 0;
}

