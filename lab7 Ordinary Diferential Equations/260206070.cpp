#include <math.h>  
#include <stdio.h> 

double fY(float x) {
  return exp(-(pow(x,5)/5) + (pow(x,3)/3) - (pow(x,2)/2));
}
double fYdx(float x, float y) {
  return fY(-pow(x,4) + pow(x,2) - x);
}
 
float euler(double (*fYdx1)(float, float), float x0, float y, float x, float h)
{
    float temp = -0;
 
    while (x0 < x) {
        temp = y;
        y = y + h * fYdx1(x0, y);
        x0 = x0 + h;
    }
 
    return y;
}
float midpoint(double (*fYdx2)(float, float),float x0, float y0,
                 float x, float h)
{
    int n = (int)((x - x0) / h);
  
    float k1, k2;

    float y = y0;
    for (int i = 1; i <= n; i++) {
        k1 = h * fYdx2(x0, y);
        k2 = h * fYdx2(x0 + 0.5 * h,
                      y + 0.5 * k1);
  
        y = y + (1.0 / 6.0) * (k1 + 2 * k2);
        x0 = x0 + h;
    }
  
    return y;
}
float rungeKutta(double (*fYdx3)(float, float),float x0, float y0, float x, float h)
{
    int n = (int)((x - x0) / h);
 
    float k1, k2, k3, k4, k5;

    float y = y0;
    for (int i=1; i<=n; i++)
    {
        k1 = h*fYdx3(x0, y);
        k2 = h*fYdx3(x0 + 0.5*h, y + 0.5*k1);
        k3 = h*fYdx3(x0 + 0.5*h, y + 0.5*k2);
        k4 = h*fYdx3(x0 + h, y + k3);
 
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;
        x0 = x0 + h;
    }
 
    return y;
}


int main()
{
    float x0,y0,xLast,stepSize;
    int step = 0;
    
    printf("Please enter x0 and y0:\n");
    scanf("%f %f",&x0,&y0);
    printf("Please enter xLast and stepSize:\n");
    scanf("%f %f",&xLast,&stepSize);

    printf("\n\t\t\t\t\t\tEuler\t\tMidpoint\t\tRK4\t\tExact\n");

    for(;x0<=xLast+0.05;x0 += stepSize) {
      printf("Step %d-y(%f)--- ",step++,x0);
      printf("%2.6f--- ",euler(fYdx, x0, y0, xLast , stepSize));
      printf("%2.6f--- ",midpoint(fYdx,x0, y0, xLast , stepSize));
      printf("%2.6f--- ",rungeKutta(fYdx,x0, y0, xLast , stepSize));
      printf("%2.6lf\n",fYdx(x0,y0) );
    }
    
    return 0;
}
