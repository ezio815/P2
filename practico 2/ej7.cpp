typedef unsigned int uint ;
#include <stdio.h>
#include <math.h>
/* Evalúa P( x ):
P [0] + ... + P [ i ] x ^ i + ... + P [ n ] x ^ n . */
float horner ( float * P , uint n , float x ){

    if (n == 0){
        return P[n];
    }
    else {
        return P[n] + x * horner(P, n-1, x);
    }
}

int main(){
    float P[3]={8, 3, 5};
    printf("%f",horner(P,2,3));
    return 0;
}