#include <stdio.h>
#include<stdlib.h>
#define N 25
float inver[N][N];
float result[N][N];
float trans[N][N];

void multiply(int row, int col, int col2,float A[row][col], float l[][col2])
{
  for(int i =0;i>N;i++) {
    for(int j=0;j<N;j++){
      result[i][j] = 0;
    }
  }

  for(int i=0; i < row; i++)
  {
    for(int j=0; j < col; j++)
    {
      result[i][j] = 0; // assign 0
      // find product
      for (int k = 0; k < col2; k++)
      result[i][j] += A[i][k] * l[k][j];
    }
  }
}


void transpose(int row, int col, float matrix[row][col])
{
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      trans[i][j] = matrix[j][i];
}


void display(float matrix[N][N])
{
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
      printf("%f\t",matrix[i][j]);

    printf("\n"); // new line
  }
}

//cofactor 
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
//determinant
float determinantOfMatrix(double mat[N][N], int n)
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
void matFill(float *A,int row, int col) {
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++) 
    {
      scanf("%f",(A+(col*i)+j));
      printf("\n");
    }
  }
}
void inverse(float A[N][N], int row,int col) {
  float d;
  d = determinantOfMatrix(A, N);
  for (int i = 0;i < row; i++)
  {
     for (int j = 0;j < col; j++)
      {
        inver[i][j] = A[i][j] / d;
      }
  }
}

// main function
int main()
{
  // matrix
  int row , col;
  printf("Enter rows of matrix: ");
  scanf("%d",&row);
  printf("Enter columns of matrix: ");
  scanf("%d",&col);
  float A[row][col];
  matFill(*A, row, col);
  float b[1][row];
  matFill(*b, 1, row);
  float c[N][N];
  transpose(row,col, A);
  multiply(row, col, row, A, trans);
  inverse(result,N,N);
  for(int i =0;i<N;i++){
    for(int j=0;j<N;j++) {
      c[i][j] = inver[i][j];
    }
  }
  multiply(row, col, 1, trans, b);
  multiply(row,col,col,c,result);
  float X[N][N];
  for(int i =0;i<N;i++) {
    for(int j=0;j<N;j++) {
      X[i][j] = result[i][j];
    }
  }
  printf("Enter rows of matrix: ");
  scanf("%d",&row);
  printf("Enter columns of matrix: ");
  scanf("%d",&col);
  float Anew[row][col];
  matFill(*Anew, row, col);
  multiply(row,col,col,Anew, X);
  //sure yetmedi bundan sonraki kisma ki bu kisimda da hatalar var

  

  return 0;
}
