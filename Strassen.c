//https://gist.github.com/wzpan/6504468
// https://github.com/sajjadpoores/strassen_matrix_multiplication3/blob/master/strassen.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------/ Declaración de Funciones /-----------------------------------------------------------------------------//

void generateRandomMatrix(int n, double **matrix);
void showMatrix(int n, double **matrix);
void matrixMultiply(int n, double **A, double **B, double **C);
void matrixSum(int n, double **A, double **B, double **C);
void strassen(int n, double **A, double **B, double **C) ;
//---------/ Funciones /-----------------------------------------------------------------------------//

void generateRandomMatrix(int n, double **matrix){
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      matrix[i][j] = rand() % 10;
}

void showMatrix(int n, double **matrix){
  for (size_t i = 0; i < n; i++) {
    if (i==0){printf(" [ " );}else{printf("[ " );}
    for (size_t j = 0; j < n; j++) {
      printf(" %g ", matrix[i][j]);
    }
    printf(" ]\n " );
  }
}

void matrixMultiply(int n, double **A, double **B, double **C){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++){
        C[i][j]=0;
          for(int k=0; k<n; k++)
              C[i][j]+=A[i][k]*B[k][j];
            }
}

void matrixSum(int n, double **A, double **B, double **C){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
              C[i][j] = A[i][j] + B[i][j];
}


//---------/ Función Principal /-----------------------------------------------------------------------------//

int main(int argc, char const *argv[]){
  int n = atoi(argv[1]);

  double **A, **B, **C;

  //Principal matrix
  A = (double **)malloc (n*sizeof(double *));
  B = (double **)malloc (n*sizeof(double *));
  C = (double **)malloc (n*sizeof(double *));

  for (int i=0;i<n;i++)
  {
    A[i] = (double *) malloc (n*sizeof(double *));
    B[i] = (double *) malloc (n*sizeof(double *));
    C[i] = (double *) malloc (n*sizeof(double *));
  }
  generateRandomMatrix(n,A);

  generateRandomMatrix(n,B);

  printf("\tA\n");
  showMatrix(n,A);

  printf("\tB\n");
  showMatrix(n,B);

  strassen(n, A, B, C);

  return 0;
}

void strassen(int n, double **A, double **B, double **C) {
  int i,j;
  double **A11, **A12, **A21, **A22, **B11, **B12, **B21, **B22;

  //Se declaran las submatrices a usar
  A11 = (double **)malloc ((n/2)*sizeof(double *));
  A12 = (double **)malloc ((n/2)*sizeof(double *));
  A21 = (double **)malloc ((n/2)*sizeof(double *));
  A22 = (double **)malloc ((n/2)*sizeof(double *));
  B11 = (double **)malloc ((n/2)*sizeof(double *));
  B12 = (double **)malloc ((n/2)*sizeof(double *));
  B21 = (double **)malloc ((n/2)*sizeof(double *));
  B22 = (double **)malloc ((n/2)*sizeof(double *));

  for (int i=0;i<n;i++)
  {
    A[i] = (double *) malloc (n*sizeof(double *));
    B[i] = (double *) malloc (n*sizeof(double *));
    A11[i] = (double *)malloc ((n/2)*sizeof(double *));
    A12[i] = (double *)malloc ((n/2)*sizeof(double *));
    A21[i] = (double *)malloc ((n/2)*sizeof(double *));
    A22[i] = (double *)malloc ((n/2)*sizeof(double *));
    B11[i] = (double *)malloc ((n/2)*sizeof(double *));
    B12[i] = (double *)malloc ((n/2)*sizeof(double *));
    B21[i] = (double *)malloc ((n/2)*sizeof(double *));
    B22[i] = (double *)malloc ((n/2)*sizeof(double *));
  }

  //Si se llega a n0 se acaba la recursividad
  if(n == 2) //2-order
  {
  	matrixMultiply(n, A, B, C);

  } else {

  	for(i=0; i<n/2; i++)
  	{printf("\tT\n");
  		for(j=0; j<n/2; j++)
  		{
              printf("\tG\n");
        			A11[i][j] = A[i][j];		printf("\tG1\n");
          		A12[i][j] = A[i][j+n/2];	printf("\tG2\n");
          		A21[i][j] = A[i+n/2][j];	printf("\tG3\n");
          		A22[i][j] = A[i+n/2][j+n/2];	printf("\tG4\n");
              printf("\tY\n");
          		B11[i][j] = B[i][j];
          		B12[i][j] = B[i][j+n/2];
          		B21[i][j] = B[i+n/2][j];
              B22[i][j] = B[i+n/2][j+n/2];
     	}
    }
  }

    printf("\tA11\n");
    showMatrix(n,A11);

    printf("\tA12\n");
    showMatrix(n,A12);

    printf("\tA21\n");
    showMatrix(n,A21);

    printf("\tA22\n");
    showMatrix(n,A22);

    printf("\tB11\n");
    showMatrix(n,B11);

    printf("\tB12\n");
    showMatrix(n,B12);

    printf("\tB21\n");
    showMatrix(n,B21);

    printf("\tB22\n");
    showMatrix(n,B22);
}
