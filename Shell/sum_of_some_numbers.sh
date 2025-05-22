#!/bin/bash
arr=(10 20 30 40)
sum=0

for num in "${arr[@]}"
do
  sum=$((sum + num))
done

echo "Sum is $sum"
