void matAdd(int nRow , int nCol, double *A, double *B);
void display(double m[3][3]);
void matMul(int nRow1, int nCol1, int nRow2, int nCol2, double A[nRow1][nCol1], double B[nRow2][nCol2]);
void matTra(int nRow, int nCol, double A[nRow][nCol]);
#include <stdio.h>
int main()
{
    double A[3][3];
    double B[3][3];
    int rows1,columns1,rows2,columns2;
    int a,k,i,j;
    printf("a matris rows: ");
    scanf("%d",&rows1);
    printf("a matris columns: ");
    scanf("%d",&columns1);
    for(i=0;i<rows1;i++) {
        for(j=0;j<columns1;j++) {
            scanf("%d",&a);
            A[i][j] = a;
        }
        printf("\n");
    }
    printf("b matris rows: ");
    scanf("%d",&rows2);
    printf("b matris columns: ");
    scanf("%d",&columns2);
    for(i=0;i<rows2;i++) {
        for(j=0;j<columns2;j++) {
            scanf("%d",&a);
            B[i][j] = a;
        }
        printf("\n");
    }
    matAdd(rows1,columns1, *A, *B);
    matMul(rows1,columns1,rows2,columns2,A,B);
    matTra(rows1,columns1,A);

    return 0;
}
void matAdd(int nRow , int nCol, double *A, double *B) 
{
    double sum[3][3];
    int i, j;
  // add both matrices
  for(i=0;i<nRow;i++){
			for(j=0;j<nCol;j++){
			
				sum[i][j]= ((A+(i)*nRow+j))+((B+(i)*nRow+j));
		}
	}
    display(sum);
    
}
void matMul(int nRow1, int nCol1, int nRow2, int nCol2, double A[nRow1][nCol1], double B[nRow2][nCol2]) 
{
    int i,j,k;
    double mul[nRow1][nRow2];
    for(i=0;i<nRow1;i++)                 
    {
        for(j=0;j<nCol1;j++)         
        {
            mul[i][j]=0;
            for(k=0;k<nCol2;k++)
            mul[i][j]=mul[i][j]+(A[i][j]*B[j][k]);
        }
    }
    display(mul);
}

void matTra(int nRow, int nCol, double A[nRow][nCol]) 
{
    int i,j;
    double tra[nRow][nCol];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            tra[i][j]=A[j][i];
    }
    display(tra);
    
}


void display(double matrix[3][3])
{
    int i,j;
    printf("\n\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++) {
            printf("%f  ",matrix[i][j]);
            printf("\n");
        }
    }
}
