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
	int j, m; /* j - jndex, k- kolejny index,  m - maksymalny stopień wielomianu*/
	
	for(j=0, m=0; j<n; j++){
		m++;
		if((n-1)/2<=m)
			m--;
	}
	return m;	
}



void make_spl(points_t * pts, spline_t * spl){

	int i, j, m;

        m = max_wielomian(pts->n);

        if (alloc_spl(spl, pts->n) == 0) {
                spl->x = pts->x;
                spl->y = pts->y;

                for (i=0 ; i <= m ; i++) {
                        spl->a[i] = 0.0;
                        spl->b[i] = 0.0;
                                for(j = 0; j < pts->n ; j++) {
                                        spl->a[i] += spl->y[j]*cos(2*M_PI*i*j/pts->n);
                                        spl->b[i] += spl->y[j]*sin(2*M_PI*i*j/pts->n);
                                }
                        spl->a[i] *= 2.0/pts->n;
                        spl->b[i] *= 2.0/pts->n;
                }
        }
}
