// ----------------
// Algebra.h
// Nathan Bain
// February 2, 2016
// ----------------

// ------------------------------------
// Double value function
// Coverts char to corresponding double
// ------------------------------------

double value ( char* term, double x);

// ----------------------------------
// Operation computer function
// Perform mathematical operations on
// two doubles
// ----------------------------------

double compute ( double x1, double x2, char op);

// --------------------------------------
// Function solver function
// Takes string funciton and double x and 
// returns the function value at x
// --------------------------------------

double function_solve ( char* function, double x);
