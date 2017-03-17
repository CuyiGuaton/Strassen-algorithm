#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
double **matrix;
double **b1;
double **b2;
double **b3;
double **b4;

void generateRandomMatrix(){
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      matrix[i][j] = rand() % 10;
    }
  }
}

void showMatrix(){
  for (size_t i = 0; i < n; i++) {
    printf("[ " );
    for (size_t j = 0; j < n; j++) {
      printf(" %g ", matrix[i][j]);
    }
    printf(" ]\n " );
  }
}

int main(int argc, char const *argv[]) {
  n = atoi(argv[1]);
  bn = n/4;

  //Principal matrix
  matrix = (double **)malloc (n*sizeof(double *));
  for (int i=0;i<n;i++)
    matrix[i] = (double *) malloc (n*sizeof(double *));

  //Matrix will be use when it split the principal matrix on 4 matrix.
  b1 = (double **)malloc (bn*sizeof(double *));
  for (int i=0;i<bn;i++)
    b1[i] = (double *) malloc (bn*sizeof(double *));

  b2 = (double **)malloc (bn*sizeof(double *));
  for (int i=0;i<bn;i++)
    b2[i] = (double *) malloc (bn*sizeof(double *));

  b3 = (double **)malloc (bn*sizeof(double *));
  for (int i=0;i<bn;i++)
    b3[i] = (double *) malloc (bn*sizeof(double *));

  b4 = (double **)malloc (bn*sizeof(double *));
  for (int i=0;i<bn;i++)
    b4[i] = (double *) malloc (bn*sizeof(double *));


  generateRandomMatrix();
  showMatrix();
  return 0;
}
