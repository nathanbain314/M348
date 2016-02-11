#!/usr/bin/env python3

from sympy.parsing.sympy_parser import parse_expr
import sympy
from sympy import pprint
import sys

def secant( f, v, p_0, p_1, n, tol):
  d = f.diff(v)
  q_0 = f.subs( v, p_0)
  q_1 = f.subs( v, p_1)

  p = 0

  for i in range( 2, n + 2 ):
    p = p_1 - q_1 * ( p_1 - p_0 ) / ( q_1 - q_0 )
    print('Iteration: ' + repr(i) + ' Value: ' + repr(p))

    if ( abs( p - p_1 ) < tol ):
      return p
    p_0 = p_1
    q_0 = q_1
    p_1 = p
    q_1 = f.subs( v, p)
  return p

# --------------------------------------------------------------
# Usage: function variable p_0 p_1 iterations tolerance_exponent
# 0 iterations = 100 iterations
# 0 tolerance = -10
# --------------------------------------------------------------
def main( args):
  f = parse_expr(args[1])
  v = parse_expr(args[2])
  p_0 = float(args[3])
  p_1 = float(args[4])
  n = int(args[5])
  tol = float(args[6])
  if ( n == 0 ): n = 100
  if ( tol == 0 ): tol = -10
  tol = 10**tol

  print()
  print( 'f(' + repr(v) + ') = ' + repr(f) )
  print( 'p_0 = ' + repr(p_0) )
  print( 'p_1 = ' + repr(p_1) )
  print()
  result = secant ( f, v, p_0, p_1, n, tol)
  print()
  print('Solution: ' + repr(result))
  print()

if __name__ == "__main__":
  main( sys.argv)
