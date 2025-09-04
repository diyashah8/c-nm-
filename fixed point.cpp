#include<stdio.h>
#include<math.h>
//defining function f(x)=sin(x)-5x+2
float f(float x){
	return sin(x)-5*x+2;
}
//define function gx=((sinx+2)/5)
float g(float x){
	return (sin(x)+2)/5;
}
//comouting approx relative error
float Error (float x1,float x2){
	return fabs ((x2-x1)/x2);
}
//main program
int main(){
	float x0, x1,E,Ear;
	int i=1;
	printf ("Enter initial guess:");
	scanf("%f",&x0);
	printf("Enter Error:");
	scanf("%f",&E);
	printf("\n Itr\t\tx0\t\tx1\t\tError");
	do{
		x1=g(x0); //calling function gx to find the value of x1
		printf("\n%d\t%f\t%f\t%f",i,x0,x1,Ear);
		Ear=Error(x0,x1); //calling function error to find the value of Ear
		x0=x1; //setting new x0=x1 for new iteration
		i++;
	}
	while(Ear>E);// looping until calculated error is less than the accepted Error
	printf("\n The final root=%f",x0);
	
}
