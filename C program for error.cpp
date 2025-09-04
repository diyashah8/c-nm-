//f(x)=x2-5
#include<stdio.h>
#include<math.h>
float f(float x){
	return x*x-5;
}float der (float x){
	return 2 * x;
}float approx (float x, float h){
	return(f(x+h)-f(x))/h;
}
int main (){
float x,h,e;
printf("enter the values of x :");
scanf("%f",&x);
printf("enter the values of h");
scanf("%f",&h);
printf("value of function at % f is %f ",x,f(x));
printf("\n derivates of function at %f is %f",x,der(x));
printf("\n approximate of function at %f is %f",x,approx(x,h));
e = der (x) - approx (x,h);
printf ("\n error = %f", fabs(e));
}

