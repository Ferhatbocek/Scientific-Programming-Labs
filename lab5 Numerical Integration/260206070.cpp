#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
double int_leftrect(double start, double finish, double n, double (*func)())
{
   double sum = 0.0, x;
   double h = (finish-start)/n;
   for(x=start; x <= (finish-h); x += h)
      sum += func(x);
   return h*sum;
}
 
double int_trapezium(double start, double finish, double n, double (*func)())
{
   double sum = func(start) + func(finish);
   int i;
   double h = (finish - start) / n;
   for(i = 1;i < n;i++)
       sum += 2.0*func(start + i * h);
   return  h * sum / 2.0;
}
int *number_of_panels_generator() {
 return 0;
}
 
double f2(double x)
{
  return 2*exp(-0.2*(x*x));
}
 
double f2a(double x)
{
  return log(x);
}
 
double f1(double x)
{
  return exp(-0.1*(x*x));
}
 
double f1a(double x)
{
  return x*x*x*x/4.0;
}
 
typedef double (pfunc)(double, double, double, double ()());
typedef double (*rfunc)(double);
 
#define INTG(F,A,B) (F((B))-F((A)))
 
int main()
{
     int i, j;
     double ic;
     pfunc f[2] = { 
       int_leftrect,  int_trapezium
     };
     const char *names[2] = {
       "leftrect", "trapezium"
     };
    
     rfunc rf[] = { f1, f2 };
     rfunc If[] = { f1a, f2a };

     //rf[2] = (double*)calloc(50, sizeof(double));
     double ivals[] = { 
       0.0, 1.0,
       1.0, 100.0,
       0.0, 5000.0,
       0.0, 6000.0
     };
     printf("\t\t\t\t\tRectf1\t\tTrapf1\t\tRectf2\t\tTrapf2\t\tRectArea\t\tTrapArea\n");
     double aprox=50;
     for (;aprox<=1000;aprox= aprox+50) {
      printf("\nnumber of panels %.0f: ",aprox);
     for(j=0; j < (sizeof(rf) / sizeof(rfunc)); j++)
     {
       
       for(i=0; i < 2 ; i++)
       {
         
         ic = (*f[i])(0.0, 30.0, aprox, rf[j]);
         printf("%+lf, %lf",
                 ic, INTG((*If[j]), 0.0, 30.0));
       }
       
     }
     }
}
