



void trasponer ( int ** A , int n ) {
    for ( int i = 1; i < n ; i++)
        for ( int j = 0; j < i ; j++) {
            int swap = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = swap ;
        }
}