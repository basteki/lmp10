#ifndef APROKSYMACJA_TRYG_H
#define APROKSYMACJA_TRYG_H

#include <stdio.h>
#include <math.h>

int max_wielomian(int n);

double a_0(double x[], int n);

double a_j(double a, double b, int n, int i, double x[]);

double b_j(double a, double b, int n, int i, double x[]);

void make_spl(points_t * pts, spline_t * spl);

#endif
