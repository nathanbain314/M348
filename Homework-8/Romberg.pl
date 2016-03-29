#!/usr/bin/perl
use Math::Expression::Evaluator;

my $f = Math::Expression::Evaluator->new;

#./Romberg.pl "function" variable a b accuracy_exponent
# Coputes integration of function using Romberg integration from a to b, to within 10^accuracy_exponent.

$function = $ARGV[0];
$var = $ARGV[1];
$a = $ARGV[2];
$b = $ARGV[3];
$accuracy = $ARGV[4];

$f->parse($function);

sub f
{
  return $f->val({$var => @_});;
}

@R1 = (0..50);
@R2 = (0..50);

$h = $b-$a;

$R1[1] = $h / 2 * (f($a) + f($b));
printf "%.10f\n",$R1[1];

for (my $i=2; ; $i++)
{
  $XI1 = 0;

  for (my $k=1; $k <= 2**($i-2); $k++)
  {
    $X = $a + ($k-.5) * $h;
    $XI1 = $XI1 + f($X);
  }
  $R2[1] = ($R1[1] + $h*$XI1) / 2;

  for (my $j=2; $j <= $i; $j++)
  {
    $R2[$j] = $R2[$j-1] + ($R2[$j-1]-$R1[$j-1])/(4**($j-1)-1);
  }
  $h=$h/2;

  for (my $j=1; $j <= $i; $j++)
  {
    printf "%.10f\t",$R2[$j];
  }
  print "\n";

  if(abs($R1[$i-1]-$R2[$i])<10**$accuracy)
  {
    last;
  }

  for (my $j=1; $j <= $i; $j++)
  {
    $R1[$j] = $R2[$j];
  }

}
