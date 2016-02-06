package com.M348.hw3;

import static java.lang.Math.*;
import java.lang.Double;
import static java.lang.System.out;
import net.objecthunter.exp4j.ExpressionBuilder;
import java.io.*;

public class Test
{
  public static void main( String [] args)
  {
    //double result = Double.parseDouble( args[0] );
    double result = new ExpressionBuilder("cos(x)").variables("x").build().setVariable("x", 3).evaluate();
    out.printf( "%f\n", result);
  }
}
