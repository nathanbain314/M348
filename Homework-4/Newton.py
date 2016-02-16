#!/usr/bin/env python3

# -----------------
# Newton.py
# Nathan Bain
# February 16, 2016
# -----------------

import sympy
from sympy import pprint, N
from sympy.parsing.sympy_parser import parse_expr
import sys

"""
f the function
v the variable
p_0 the initial p value
n the maximum number of iterations
tol the minimum tolerance required
return the approximate solution
"""
def newton( f, v, p_0, n, tol):
  d = f.diff(v)
  p = 0

  for i in range( 1, n + 1):
    p = N(p_0 - f.subs( v, p)/d.subs( v, p_0))
    print('Iteration: ' + repr(i) + '        \tValue: ' + repr(p) )

    if ( abs( p - p_0 ) < tol ):
      return p
    p_0 = p

  return p

# --------------------------------------------------------------
# Usage: function variable p_0 iterations tolerance_exponent
# 0 iterations = 100 iterations
# 0 tolerance = -10
# --------------------------------------------------------------
def main( args):
  f = parse_expr(args[1])
  v = parse_expr(args[2])
  p_0 = float(args[3])
  n = int(args[4])
  tol = float(args[5])
  if ( n == 0 ): n = 100
  if ( tol == 0 ): tol = -10
  tol = 10**tol

  print()
  print( 'f(' + repr(v) + ') = ' + repr(f) )
  print( 'p_0 = ' + repr(p_0) )
  print( 'E = 10^' + args[5])
  print()
  result = newton( f, v, p_0, n, tol)
  print()
  print( 'Solution: ' + repr(result) )
  print()

if __name__ == "__main__":
  main( sys.argv)
