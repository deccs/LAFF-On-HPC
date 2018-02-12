#include <stdio.h>
#include <stdlib.h>

#define alpha( i,j ) A[ (j)*ldA + i ]   // map alpha( i,j ) to array A 
#define beta( i,j )  B[ (j)*ldB + i ]   // map beta( i,j )  to array B
#define gamma( i,j ) C[ (j)*ldC + i ]   // map gamma( i,j ) to array C

void Gemm_IJP( int, int, int, const double *, int, const double *, int, double *, int );

void GemmWrapper( int m, int n, int k, const double *A, int ldA,
		  const double *B, int ldB, double *C, int ldC )
{
  Gemm_IJP( m, n, k, A, ldA, B, ldB, C, ldC );
}


void Gemm_IJP( int m, int n, int k,
               const double *A, int ldA,
               const double *B, int ldB,
               double *C, int ldC )
{
  for ( int i=0; i<m; i++ )
    for ( int j=0; j<n; j++ )
      for ( int p=0; p<k; p++ )
        gamma( i,j ) += alpha( i,p ) * beta( p,j );
}
  