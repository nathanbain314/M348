#!/usr/bin/env ruby
require 'dentaku'

# ./Eulers.rb function a b alpha h

function = ARGV[0]
a = ARGV[1].to_f
b = ARGV[2].to_f
alpha = ARGV[3].to_f
h = ARGV[4].to_f

calculator = Dentaku::Calculator.new

t = a
w = alpha

i = 0
while t < b
  w = w + h * calculator.evaluate(function, t: t, y: w)
  t = a + i * h
  print t, " "
	puts w
	i = i + 1
end
