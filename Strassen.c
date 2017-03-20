#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void generateRandomMatrix(int n, double **matrix){
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      matrix[i][j] = rand() % 10;
    }
  }
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
