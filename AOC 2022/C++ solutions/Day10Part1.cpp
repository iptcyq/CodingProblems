#include<iostream>
#include <fstream>
#include <string>
using namespace std;

bool inRange(int value) { //check if cycle in desired range
  value -= 20;
  return (value==0) || (value/40>0 && value/40<6 && value%40==0);
}

int Add(int cycle, int num){ //add number as signal stength 
  if (inRange(cycle)){ //check if cycle is in desired range
    cout << cycle << " "<< num << "  " << cycle*num << endl;
    return cycle*num;
  }
  return 0; //otherwise do not add
}

int main(){
  string s;
  ifstream dataFile("aoc22day10.txt");

  int cycle = 0;
  int X = 1;
  int SigStrength = 0;
  while (getline(dataFile, s)) {
    if (s=="noop"){cycle++; SigStrength+=Add(cycle, X);} //1 cycle
    else {
      int AddNum = stoi(s.substr(5,s.length()-5));
      for (int i=0; i<2; i++){ //loop through 2 cycles
        cycle++;
        SigStrength+=Add(cycle, X);
      }
      X += AddNum;
    }
  }
  cout << SigStrength << endl; //print result
}