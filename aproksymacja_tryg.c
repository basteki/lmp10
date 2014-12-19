#include "makespl.h"
#include "piv_ge_solver.h"
#include "aproksymacja_tryg.h"
#include "points.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/*
 * Funkcje bazowe: 
 * n - liczba punktów
 * a,b - granice przedzialu aproksymacji 
 * x - wspolrzedna dla ktorej obliczana jest wartosc funkcji
 *
 * M_PI - liczba Pi, z biblioteki math.h
 
 f(x) = a0 + sumaA + sumaB
 
 */
 

 
int max_wielomian(int n){
	int j,k,m; /* j - jndex, k- kolejny index,  m - maksymalny stopień wielomianu*/
	
	for(j=0, m=0; j<n; j++){
		m++;
		if((n-1)/2<=m)
			m--;
	}
	return m;	
}


/*Współczynnik a0 jest średnią arytmetyczną x[1-n]*/

double a_0(double x[], int n){
	double suma = 0;
    int j;
	for (j=0; j<n; j++){
        suma+=x[j];
    }
    
	suma=suma/n;
    return suma;    
}
/*Współczynnik aj (j = 1,2..., m)*/
double a_j(double a, double b, int n, int i, double x[n]){
	int j, m;
	double sumaA = 0;
	
	m = max_wielomian(n);
	
	for(j = 0; j<=m; j++){
		sumaA += x[j-1]*cos(2*M_PI*i*j/n);
		}
	return sumaA*2/n;
}

/*Współczynnik bj (j = 1,2..., m)*/
double b_j(double a, double b, int n, int i, double x[n]){
	int j, m;
	double sumaB = 0;
	
	m = max_wielomian(n);
	
	for(j = 0; j<=m; j++){
		sumaB += x[j-1]*sin(2*M_PI*i*j/n);
		}
	return sumaB*2/n;
}



void make_spl(points_t * pts, spline_t * spl){

	matrix_t       *eqs= NULL;
	double         *x = pts->x;
	double         *y = pts->y;
	double		a = x[0];
	double		b = x[pts->n - 1];
	int		i, j, k;
	int		nb = pts->n - 3 > 10 ? 10 : pts->n - 3;
	
	char *nbEnv= getenv( "APPROX_BASE_SIZE" );

	if( nbEnv != NULL && atoi( nbEnv ) > 0 )
		nb = atoi( nbEnv );

	eqs = make_matrix(nb, nb + 1);
}
