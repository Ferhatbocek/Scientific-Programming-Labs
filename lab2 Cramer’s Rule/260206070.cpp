#include <stdio.h>
#include <math.h>
#define N 3
double Dxyz[N][N] = {0};
double A[N][N]= {0}; 
double I[N][N]= {0};
double determinantOfMatrix(double mat[N][N], int n);
void display(double mat[N][N], int row, int col);
void transpose(double num[N][N], double fac[N][N], float r);
double determinantOfMatrix(double mat[N][N], int n);
void Identity(double I[N][N]) 
{
  for (int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j)
        I[i][j] = 1.0;
      else
        I[i][j] = 0.0;
    }
  }
}
void CreateDxyz_mat(double A[N][N],double I[N][N],int A_colNum,double Dxyz[N][N],int invA_colNum) { // for col 1› invA_colNum=0, col 2› invA_colNum=1, col 3› invA_colNum=2
for (int i=0;i<N;i++){
  for(int j=0;j<N;j++){
    if (j==A_colNum)
      Dxyz[i][j]=I[i][invA_colNum];
    else
      Dxyz[i][j]=A[i][j];
  }
}
printf("\n");
display(Dxyz, N, N);
printf("\nDeterminant of the matrix is :  %lf",determinantOfMatrix(Dxyz,N));

}
void CramersRuleForInverse(double A[N][N]) {
Identity(I);
for(int j=0;j<N;j++) {
for(int i=0;i<N;i++){
  Identity(I);
  CreateDxyz_mat(A,I,i,Dxyz,i);
  

}}
}

// Function to get cofactor of mat[p][q] in temp[][]. n is
// current dimension of mat[][]
void getCofactor(double mat[N][N], double temp[N][N], int p,
                 int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++) 
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q) 
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
double determinantOfMatrix(double mat[N][N], int n)
{
    double D = 0; // Initialize result
 
    
    if (n == 1)
        return mat[0][0];
 
    double temp[N][N]; 
 
    int sign = 1; 
 
    for (int f = 0; f < n; f++) 
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f]
             * determinantOfMatrix(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
void cofactor(double num[N][N], int f)
{
 double b[N][N], fac[N][N];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinantOfMatrix(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
void transpose(double num[N][N], double fac[N][N], float r)
{
  int i, j;
  double b[N][N], inverse[N][N], d;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinantOfMatrix(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");
  display(inverse, N, N);
   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }
} 
 
/* function for displaying the matrix */
void display(double mat[N][N], int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
            printf("  %lf", mat[i][j]);
        printf("\n");
    }
}

// Driver program to test above functions
int main()
{
    for(int i=0; i<N;i++) { 
      for(int j=0; j<N;j++) { 
      printf("Enter the element of matrix [%d][%d] ",i+1,j+1); 
      scanf("%lf",&A[i][j]); 
      } 
    }
    double d = determinantOfMatrix(A, N);
    printf("A matricies");
    display(A, N, N);
    printf("\nDeterminant of the matrix is : %lf\n",d);
    
  CramersRuleForInverse(A);
    // Function call
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   cofactor(A, N);
    
     
}
