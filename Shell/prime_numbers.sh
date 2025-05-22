#!/bin/bash
read -p "Enter a number: " n
is_prime=1

for (( i=2; i<=n/2; i++ ))
do
  if [ $((n % i)) -eq 0 ]; then
    is_prime=0
    break
  fi
done

if [ $is_prime -eq 1 ]; then
  echo "$n is prime"
else
  echo "$n is not prime"
fi
