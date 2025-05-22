#!/bin/bash
file="test.txt"

if [ -e "$file" ]; then
  echo "File exists"
else
  echo "File does not exist"
fi
