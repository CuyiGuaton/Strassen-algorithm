void generateRandomMatrix(int n; double **matrix);
void showMatrix(int n; double **matrix);

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
