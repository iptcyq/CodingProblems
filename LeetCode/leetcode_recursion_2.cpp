#include<iostream>
using namespace std;

/*
https://leetcode.com/problems/fibonacci-number/description/
*/

int fib(int n) {
  if (n<=1) {return n;}
  return fib(n-1) + fib(n-2);
}