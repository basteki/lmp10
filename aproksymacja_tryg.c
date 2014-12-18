#include "makespl.h"
#include "piv_ge_solver.h"
#include "aproksymacja_tryg.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/*
 * Funkcje bazowe: 
 * n - liczba punktów
 * a,b - granice przedzialu aproksymacji 
 * x - wspolrzedna dla ktorej obliczana jest wartosc funkcji
 */
 
aproks_tryg((double a, double b, int n, int i, double x){
	int j,k,m; /* j - jndex, k- kolejny index,  m - maksymalny stopień wielomianu*/
	
	for(j=0, m=0; j<n; j++){
		m++;
		if((n-1)/2=<m)
			m--;
	}		
	
	double y [m];
	
	y[0] = 0 /* ?? */
	
}