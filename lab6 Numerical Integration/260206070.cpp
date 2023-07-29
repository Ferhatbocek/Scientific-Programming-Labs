#include<stdio.h>

#include<math.h>

#define pi 3.142857
#define start 0.0
#define finish 10.0
const double eps=1e-12;
/*Function definition to perform integration by Simpson's 1/3rd Rule */
double phi_t(double t) {
  return sin((4*pi*t));
}

double phi_diff(double (*f)(double), double x0)
{
    const double delta = 1.0e-6;
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

double xt(double t,double x){

    return 0.5*cos((20*pi*t + phi_diff(phi_t, x))) +phi_t(x);

}

double simpsons(double x,double f(double t,double x),int n){

  double h,integral,t,sum=0;

  int i;

  h=fabs(finish-start)/n;

  for(i=1;i<n;i++){

    t=start+i*h;

    if(i%2==0){

      sum=sum+2*f(t,x);

    }

    else{

      sum=sum+4*f(t,x);

    }

  }

  integral=(h/3)*(f(t,start)+f(t,finish)+sum);

  return integral;

}

double simpson(double l,double r,int n){
  double h=fabs(finish-start)/n;
  return (r-l)/6*(xt(l,h)+4*xt((l+r)/2,h)+xt(r,h));
}


double adaptive_simpson(double f(double t,double x),double l, double r, int n, double ans)
{
      double h=fabs(finish-start)/n;
    	
      double m=(l+r)/2.0;
      double x= simpson(l, r,n);
      double y= simpson(m, r,n);

    	if(abs(x+y-ans)<eps)
        return x+y;
    	return adaptive_simpson(xt(l,h),l,m,n,x)+adaptive_simpson(xt(m,h),m,r,n,y);
}

double printBisection(double f(double x),double a, double b, double eps, int maxSteps){

  double c;

  if(f(a)*f(b)<=0){

    int iter=1;

    /Bisection Method begins that tabulates the various values at each iteration/

    printf("__________\n");

    printf("iter\ta\t\tb\t\tc\t\tf(c)\t\t|a-b|\n");

    printf("__________\n");

    do{

      c=(a+b)/2;

      printf("%d.\t%lf\t%lf\t%lf\t%lf\t%lf\n",iter,a,b,c,f(c),fabs(a-b));

      if(f(a)*f(c)>0){

      a=c;

    }

    else if(f(a)*f(c)<0){

      b=c;

    }

      iter++;

          

    }while(fabs(a-b)>=eps&&iter<=maxSteps);

    printf("___________\n");

    return c;

  }

  else{

    printf("\nSorry! Either the root doesn't exist in the given interval or there are multiple roots in this interval.\nPlease enter a different set of guesses.\n");

    return 9999;

  }

}

main(){

    //no more time


    }
