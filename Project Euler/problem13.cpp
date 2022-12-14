#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

int main(){
  string s;
  long sum;
  ifstream dataFile("euler.txt");

  //since only 10 digits are needed, ~20 digits may be enough
  while (getline(dataFile, s)) {
    sum += stol(s.substr(0,20));
  }
  cout << sum << endl;
}
