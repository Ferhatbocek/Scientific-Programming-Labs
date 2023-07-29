#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define pi 3.14
double d =0.5;
double L = 1.4;
double lambdaG = 3.6;
double a = 2.28;
int iteration;
double e_r(double x) {
  return (pow((a/d),2)*pow((x/pi),2) +1) / (pow(((2*a)/lambdaG),2) +1);
}
double K() {
  return (tan((2*pi*(d+L))/lambdaG)/((2*pi*(d/lambdaG))));
}
double f(double x){
  return tan(x) - K();
}
double  f_prime(double x){
  return pow((1.0/cos(x)),2) - K();
}
double  degree_to_radian(double *x)
{
    return (*x * (pi / 180.0));
}
double *tolerance_value_generator() { 
  static double tolerance = 0.00000001;
  tolerance *= 10.0;
  return &tolerance;
}
double *newtonsAlgorithm(double tolerance, double x) {
  {
    iteration = 0;
    double h = f(x) / f_prime(x);
    while (fabs(h) >= tolerance)
    {
        h = f(x)/f_prime(x);
        x = x - h;
        iteration++;
    }
  
    return &x;
  }
}
int main(){
  double x=300,tol,newtonX;
  while(x<90 || x>270) {
    printf("\nInitial point in degrees (Between 90 and 270): ");
    scanf("%lf",&x);
  }
  x = degree_to_radian(&x);
  int i=0;
  while(i<6) {
    tol = *tolerance_value_generator();
    newtonX = *newtonsAlgorithm(tol,x);
    
    printf("\n\nTolerance: %1.7lf",tol);
    printf("\nRoot of f(x) when x is radians: %lf",newtonX);
    printf("\nDielectric constant (e_r) : %lf",e_r(newtonX));
    printf("\nNumber of iterations: %d" ,iteration);

    i++;
  } 

	return 0;
}
