package com.M348.hw3;

// Import exp4j for algebra
import net.objecthunter.exp4j.Expression;
import net.objecthunter.exp4j.ExpressionBuilder;

import static java.lang.System.out;
import java.lang.Double;
import java.lang.Integer;
import java.io.*;

public class FixedPoint
{
  // --------------------------------------------------
  // Computes fixed point using iteration method
  // Finds p such that p = e(p) starting with guess p_0
  // for up to iter iterations and to accuracy tol
  // --------------------------------------------------
  public static double IterationMethod ( Expression e, String var, double p_0, int iter, double tol)
  {
    double p = 0;
    
    for ( int i = 1 ; i <= iter; ++i )
    {
      p = e.setVariable( var, p_0 ).setVariable( "pi", Math.PI).setVariable( "e", Math.E).evaluate();
      out.printf("Iteration: %d Approximate value: %.17f\n", i, p);
      if ( Math.abs( p - p_0 ) < tol )
      {
        return p;
      }
      p_0 = p;
    }
    return p; 
  }
  
  // -------------------------------------------------
  // Finds approximate solution using iteration method
  // Requires function, variable, number of iterations
  // and tolerance exponent
  // Also accepts guess or start and end of range
  // 0 iterations defaults to 100
  // 0 tolerance exponent changes to -10
  // -------------------------------------------------
  public static void main( String [] args)
  {
    double guess, start, end, tol;
    guess = 1;
    if ( args.length < 3 ) {
      System.err.println( "Usage: FixedPoint function variable iteration_limit tol [guess] [start end]" );
      System.exit( -1 );
    }
    else if ( args.length == 5 || args.length > 6 )
    {
      guess = Double.parseDouble( args[4] );
    }
    else if ( args.length == 6 )
    {
      start = Double.parseDouble( args[4] );
      end = Double.parseDouble( args[5] );
      guess = ( start + end ) / 2;
    }

    int iter = Integer.parseInt( args[2] );
    tol = Double.parseDouble( args[3] );
    if ( iter == 0 ) iter = 100;
    if ( tol == 0 ) tol = -10;

    tol = Math.pow( 10, tol);

    out.printf("\nf(%s) = %s\np_0 = %f\n\n", args[1], args[0], guess);

    Expression e = new ExpressionBuilder(args[0]).variables(args[1], "pi", "e").build();
    double result = IterationMethod( e, args[1], guess, iter, tol);
    
    out.printf( "\nSolution = %f\n", result);
  }
}
