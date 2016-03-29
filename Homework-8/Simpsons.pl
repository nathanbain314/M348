#!/usr/bin/perl
use Math::Expression::Evaluator;

my $f = Math::Expression::Evaluator->new;

#./Simpsons.pl "function" variable a b n
# Coputes integration of function using the composite Simpson's rule from a to b for n intervals.

$function = $ARGV[0];
$var = $ARGV[1];
$a = $ARGV[2];
$b = $ARGV[3];
$n = $ARGV[4];

$f->parse($function);

sub f
{
  return $f->val({$var => @_});;
}

$h = ($b-$a)/$n;

$XI0 = f($a) + f($b);
$XI1 = 0;
$XI2 = 0;

for (my $i=1; $i < $n; $i++)
{
  $X = $a + $i * $h;
  if ( $i % 2 == 0 )
  {
    $XI2 = $XI2 + f($X);
  }
  else
  {
    $XI1 = $XI1 + f($X);
  }
}
$XI = $h * ($XI0 + 2*$XI2 + 4*$XI1) / 3;
print "$XI\n"
