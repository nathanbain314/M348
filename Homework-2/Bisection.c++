// ----------------
// Bisection.c++
// Nathan Bain
// February 2, 2016
// ----------------

// --------
// includes
// --------

#include <cstdlib>  // strtod
#include <cstring>  // strtok
#include <cmath>    // pow, exp
#include <cstdio>   // printf
#include "Algebra.h"

using namespace std;

// ----------------------------------------------
// Bisection solver function
// Uses the bisection method for computing zeroes
// to approximate function's zero between a and b
// to within tolerance.
// ----------------------------------------------

double bisection_solve ( char* function, double a, double b, double tolerance)
{
  double fa, fp, p;
  int i = 1;

  // ---------------------------
  // Compute function value at a
  // ---------------------------

  fa = function_solve( function, a);

  while( i < 100) // Safeguard
  {
    p = a + (b - a)/2;
    fp = function_solve( function, p);
    printf("Iteration:  %2d\tApproximate root: % 02.10f  Function value: % 02.10f\n", i, p, fp);

    if( fp == 0 || (b - a) / 2 < tolerance) return p;

    ++i;

    if( fa * fp > 0)
    {
      a = p;
      fa = fp;
    }
    else
    {
      b = p;
    }
  }
}  

int main ( int argc, char* argv[]) 
{
  double result, a, b;
  a = strtod(argv[2], NULL);
  b = strtod(argv[3], NULL);
  printf("--------------------------------------------------------------\n");
  printf("f(x) = %s\t[ %.2f, %.2f]\t\u03b5=10^%s\n", argv[1], a, b, argv[4]);
  printf("--------------------------------------------------------------\n");
  result = bisection_solve( argv[1], a , b, pow(10, atoi(argv[4])));
  printf("--------------------------------------------------------------------\n");
  printf("The solution between %.2f and %.2f is approximately %f\n", a, b, result);
  printf("--------------------------------------------------------------------\n");
  return 0;
}
