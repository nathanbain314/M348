// ----------------
// Algebra.c++
// Nathan Bain
// February 2, 2016
// ----------------

// --------
// includes
// --------

#include <cstdlib>  // strtod
#include <cstring>  // strtok
#include <cmath>    // pow, exp
#include "Algebra.h"

using namespace std;

// ------------------------------------
// Double value function
// Coverts char to corresponding double
// ------------------------------------

double value ( char* term, double x)
  {
  if( term[0] == 'e') return exp(1);
  if( term[0] == 'x') return x;
  return strtod( term, NULL);
}

// ----------------------------------
// Operation computer function
// Perform mathematical operations on
// two doubles
// ----------------------------------

double compute ( double x1, double x2, char op)
{
  switch( op)
  {
    case '^':
      return pow( x1, x2);
    case '*':
      return x1 * x2;
    case '/':
      return x1 / x2;
    case '+':
      return x1 + x2;
    case '-':
      return x1 - x2;
  }
  return 0;
}

// --------------------------------------
// Function solver function
// Takes string funciton and double x and 
// returns the function value at x
// --------------------------------------

double function_solve ( char* function, double x)
{
  char op;
  char * opset = "^*/-+";
  int i, j, k, count = 0;

  // -----------------------------------------
  // Set up the array of values and operations
  // -----------------------------------------

  char * copy = strdup(function);
  char * part = strtok( copy, opset);
  while( part != NULL)
  {
    ++count;
    part = strtok( NULL, opset);
  }

  copy = strdup(function);
  double parts[ count];
  char ops[ count - 1];
  part = strtok( copy, opset);
  parts[ 0] = value( part, x);

  for( i = 1; i < count; ++i)
  {
    ops[ i - 1] = function[ part - copy + 1];
    part = strtok( NULL, opset);
    parts[ i] = value( part, x);
  }

  // -------------------------------------------
  // Reduce function through order of operations
  // until only one value remains
  // -------------------------------------------

  for( i = 0; i < 5; ++i)
  {
    j = 0;
    while( j < count)
    {
      if( opset[ i] == ops[ j])
      {
        parts[ j] = compute( parts[ j], parts[ j + 1], ops[j]);
        for( k = j + 1; k < count; ++k)
        {
          ops[ k - 1] = ops[ k];
          parts[ k] = parts[ k + 1];
        }
        --count;
      }
      else ++j;
    }
  }

  return parts[ 0];
}