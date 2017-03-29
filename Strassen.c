////////Fuentes, agrema más si encontrás
//https://gist.github.com/wzpan/6504468
// https://github.com/sajjadpoores/strassen_matrix_multiplication3/blob/master/strassen.cpp

//----------------------------------------------------------------------------------------//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------/ Declaración de Funciones /-----------------------------------------------------------------------------//

void generateRandomMatrix(int n, double **matrix);
void showMatrix(int n, double **matrix);
void matrixMultiply(int n, double **A, double **B, double **C);
void matrixSum(int n, double **A, double **B, double **C);
void strassen(int n, double **A, double **B, double **C);
void matrixSub(int n, double **A, double **B, double **result);
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

//Multiplica matgrices
void matrixMultiply(int n, double **A, double **B, double **result){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++){
        result[i][j]=0;
          for(int k=0; k<n; k++)
              result[i][j]+=A[i][k]*B[k][j];
            }
}

//Suma matries
void matrixSum(int n, double **A, double **B, double **result){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
              result[i][j] = A[i][j] + B[i][j];
}

//Resta matrix
void matrixSub(int n, double **A, double **B, double **result){
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
              result[i][j] = A[i][j] - B[i][j];
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

  printf("\tC\n");
  showMatrix(n,C);
  return 0;
}

void strassen(int n, double **A, double **B, double **C) {
  int i,j;
  double **A11, **A12, **A21, **A22, **B11, **B12, **B21, **B22, **S1,**S2,**S3,**S4,**T1,**T2,**T3,**T4,**P1,**P2, **P3,**P4,**P5,**P6,**P7,**U1,**U2,**U3,**U4,**U5,**U6,**U7;

  //Se declaran las submatrices a utilizar
  A11 = (double **)malloc ((n/2)*sizeof(double *));
  A12 = (double **)malloc ((n/2)*sizeof(double *));
  A21 = (double **)malloc ((n/2)*sizeof(double *));
  A22 = (double **)malloc ((n/2)*sizeof(double *));
  B11 = (double **)malloc ((n/2)*sizeof(double *));
  B12 = (double **)malloc ((n/2)*sizeof(double *));
  B21 = (double **)malloc ((n/2)*sizeof(double *));
  B22 = (double **)malloc ((n/2)*sizeof(double *));
  S1 = (double **)malloc ((n/2)*sizeof(double *));
  S2 = (double **)malloc ((n/2)*sizeof(double *));
  S3 = (double **)malloc ((n/2)*sizeof(double *));
  S4 = (double **)malloc ((n/2)*sizeof(double *));
  T1 = (double **)malloc ((n/2)*sizeof(double *));
  T2 = (double **)malloc ((n/2)*sizeof(double *));
  T3 = (double **)malloc ((n/2)*sizeof(double *));
  T4 = (double **)malloc ((n/2)*sizeof(double *));
  P1 = (double **)malloc ((n/2)*sizeof(double *));
  P2 = (double **)malloc ((n/2)*sizeof(double *));
  P3 = (double **)malloc ((n/2)*sizeof(double *));
  P4 = (double **)malloc ((n/2)*sizeof(double *));
  P5 = (double **)malloc ((n/2)*sizeof(double *));
  P6 = (double **)malloc ((n/2)*sizeof(double *));
  P7 = (double **)malloc ((n/2)*sizeof(double *));
  U1 = (double **)malloc ((n/2)*sizeof(double *));
  U2 = (double **)malloc ((n/2)*sizeof(double *));
  U3 = (double **)malloc ((n/2)*sizeof(double *));
  U4 = (double **)malloc ((n/2)*sizeof(double *));
  U5 = (double **)malloc ((n/2)*sizeof(double *));
  U6 = (double **)malloc ((n/2)*sizeof(double *));
  U7 = (double **)malloc ((n/2)*sizeof(double *));


  for (int i=0;i<n;i++)
  {
    A11[i] = (double *)malloc ((n/2)*sizeof(double *));
    A12[i] = (double *)malloc ((n/2)*sizeof(double *));
    A21[i] = (double *)malloc ((n/2)*sizeof(double *));
    A22[i] = (double *)malloc ((n/2)*sizeof(double *));
    B11[i] = (double *)malloc ((n/2)*sizeof(double *));
    B12[i] = (double *)malloc ((n/2)*sizeof(double *));
    B21[i] = (double *)malloc ((n/2)*sizeof(double *));
    B22[i] = (double *)malloc ((n/2)*sizeof(double *));
    S1[i] = (double *)malloc ((n/2)*sizeof(double *));
    S2[i] = (double *)malloc ((n/2)*sizeof(double *));
    S3[i] = (double *)malloc ((n/2)*sizeof(double *));
    S4[i] = (double *)malloc ((n/2)*sizeof(double *));
    T1[i] = (double *)malloc ((n/2)*sizeof(double *));
    T2[i] = (double *)malloc ((n/2)*sizeof(double *));
    T3[i] = (double *)malloc ((n/2)*sizeof(double *));
    T4[i] = (double *)malloc ((n/2)*sizeof(double *));
    P1[i] = (double *)malloc ((n/2)*sizeof(double *));
    P2[i] = (double *)malloc ((n/2)*sizeof(double *));
    P3[i] = (double *)malloc ((n/2)*sizeof(double *));
    P4[i] = (double *)malloc ((n/2)*sizeof(double *));
    P5[i] = (double *)malloc ((n/2)*sizeof(double *));
    P6[i] = (double *)malloc ((n/2)*sizeof(double *));
    P7[i] = (double *)malloc ((n/2)*sizeof(double *));
    U1[i] = (double *)malloc ((n/2)*sizeof(double *));
    U2[i] = (double *)malloc ((n/2)*sizeof(double *));
    U3[i] = (double *)malloc ((n/2)*sizeof(double *));
    U4[i] = (double *)malloc ((n/2)*sizeof(double *));
    U5[i] = (double *)malloc ((n/2)*sizeof(double *));
    U6[i] = (double *)malloc ((n/2)*sizeof(double *));
    U7[i] = (double *)malloc ((n/2)*sizeof(double *));
  }

  //Si se llega a n0 se acaba la recursividad
  if(n <= 4) //2-order
  {
  	matrixMultiply(n, A, B, C);

  } else {
  	for(i=0; i<n/2; i++)
  		for(j=0; j<n/2; j++){
//----/ Se dan los valores a las SubMatrices /----------------------------//	
			A11[i][j] = A[i][j];
          		A12[i][j] = A[i][j+n/2];
          		A21[i][j] = A[i+n/2][j];
          		A22[i][j] = A[i+n/2][j+n/2];

          		B11[i][j] = B[i][j];
          		B12[i][j] = B[i][j+n/2];
          		B21[i][j] = B[i+n/2][j];
              		B22[i][j] = B[i+n/2][j+n/2];
     	}

//----/ Muestra las subMatrices /---------------------------------//

  printf("\n SubMatrices de "); printf("%i",(n/2)); printf("x"); printf("%i",(n/2)); printf(":"); printf("\n\n");

  printf("\tA11\n");
  showMatrix((n/2),A11);

  printf("\tA12\n");
  showMatrix((n/2),A12);

  printf("\tA21\n");
  showMatrix((n/2),A21);

  printf("\tA22\n");
  showMatrix((n/2),A22);

  printf("\tB11\n");
  showMatrix((n/2),B11);

  printf("\tB12\n");
  showMatrix((n/2),B12);

  printf("\tB21\n");
  showMatrix((n/2),B21);

  printf("\tB22\n");
  showMatrix((n/2),B22);

  printf("\n");

//----/ Primera secuencia de sumas/restas de matrices /----------------------//

      //S1 = A21 + A22
      matrixSum(n/2,A21,A22,S1);

      //S2 = S1 - A11
      matrixSub(n/2,S1,A11,S2);

      //S3 = A11 - A21
      matrixSub(n/2,A11,A21,S3);

      //S4 = A12 - S2
      matrixSub(n/2,A12,S2,S4);

      //T1 = B12 - B11
      matrixSub(n/2,B12,B11,T1);

      //T2 = B22 - T1
      matrixSub(n/2,B22,T1,T2);

      //T3 = B22 - B12
      matrixSub(n/2,B22,B12,T3);

      //T4 = T2 - B21
      matrixSub(n/2,T2,B21,T4);

//----/ Secuencia de productos de matrices /----------------------//

      //P1 = A11*B11
      strassen(n/2, A11,B11,P1);

      //P2 = A12*B21
      strassen(n/2,A12,B21,P2);

      //P3 = S4*B22
      strassen(n/2,S4,B22,P3);

      //P4 = A22*T4
      strassen(n/2,A22,T4,P4);

      //P5 = A22*T4
      strassen(n/2,S1,T1,P5);

      //P6 = S2*T2
      strassen(n/2,S2,T2,P6);

      //P7 = S3*T3
      strassen(n/2,S3,T3,P7);

//----/ Segunda secuencia de sumas/restas de matrices / Sacamos valores de los U /----------------------//

      //U1 = P1 + P2
      matrixSum(n/2,P1,P2,U1);

      //U2 = P1 + P6
      matrixSum(n/2,P1,P6,U2);

      //U3 = U2 + P7
      matrixSum(n/2,U2,P7,U3);

      //U4 = U2 + P5
      matrixSum(n/2,U2,P5,U4);

      //U5 = U4 + P3
      matrixSum(n/2,U4,P3,U5);

      //U6 = U3 - U4
      matrixSub(n/2,U3,P4,U6);

      //U7 = U3 + P5
      matrixSum(n/2,U3,P5,U7);

//----/ Obtenemos el producto AB /--------------------------------------------------------------//

        for(i=0; i<n/2; i++) {
           for(j=0; j<n/2; j++) {
              C[i][j] = U1[i][j];
              C[i][j+n/2] = U5[i][j];
              C[i+n/2][j] = U6[i][j];
              C[i+n/2][j+n/2] = U7[i][j];
           }
        }
    }
}
