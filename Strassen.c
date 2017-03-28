#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateRandomMatrix(int n, double **matrix);
void showMatrix(int n, double **matrix);
void matrixMultiply(int n, double **A, double **B, double **C);
void matrixSum(int n, double **A, double **B, double **C);

void generateRandomMatrix(int n, double **matrix){
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      matrix[i][j] = rand() % 10;

}

void showMatrix(int n, double **matrix){
  for (size_t i = 0; i < n; i++) {
    printf("[ " );
    for (size_t j = 0; j < n; j++) {
      printf(" %g ", matrix[i][j]);
    }
    printf(" ]\n " );
  }
}

void matrixMultiply(int n, double **A, double **B, double **C){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
          for(int k=0; k<n; k++)
              C[i][j]+=A[i][k]*B[k][j];
}

void matrixSum(int n, double **A, double **B, double **C){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
              C[i][j] = A[i][j] + B[i][j];
}

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);

  double **matrix;
  //Principal matrix
  matrix = (double **)malloc (n*sizeof(double *));
  for (int i=0;i<n;i++)
    matrix[i] = (double *) malloc (n*sizeof(double *));

  generateRandomMatrix(n,matrix);
  showMatrix(n,matrix);

  return 0;
}
