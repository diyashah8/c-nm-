#include<stdio.h>
#include<math.h>
float f(float x)
{
	return exp(x)-3*x;
}
float df(float x){
	return exp(x)-3;
}
float error(float x1,float x2)
{
	return fabs ((x2-x1)/x2);
}
float root (float x1){
	return (x1-(f(x1)/df(x1)));
}
int main(){
	float x1,x2,E,Ear;
	int i=1;
	printf("Enter a initial guesses:");
	scanf("%f",&x1);
	printf("Enter a precise error to be consider:");
	scanf("%f",&E);
	printf("Itr(i)\tx1\t\tf(xi)\t\tf(xi)\t\tf(x+i)\t\tError");
	do{
		x2=root(x1);
		printf("\n%d\t%f\t\t%f\t\t%f\t\t%f\t\t%f",i,x1,f(x1),df(x1),x2);
		Ear=error(x1,x2);
		x1=x1;
		i++;
	}
	while(Ear>E);
	printf("\n The final root=%f",x2);
	}
