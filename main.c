#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
double **matrix;


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
  matrix = (double **)malloc (n*sizeof(double *));
  for (int i=0;i<n;i++)
    matrix[i] = (double *) malloc (n*sizeof(double *));
  generateRandomMatrix();
  showMatrix();
  return 0;
}
