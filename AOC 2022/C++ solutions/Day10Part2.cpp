#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

/*
It's throwing me an error at cycle 200 where it gets a negative number (???) 
The debugged output also looks wrong for some reason - no idea how to fix and solve
*/

vector<string> img = 
  {"........................................",
  "........................................",
  "........................................",
  "........................................",
  "........................................",
  "........................................"};

void Draw(int cycle, int num){ //draw the pixel 
  if (cycle<240){
    //cout << num << endl;
    //if (img[floor(cycle/40)].at(num) == '#'){num++;}
    img[floor(cycle/40)].at(num) = '#';
    //cout << floor(cycle/40) << " " << img[floor(cycle/40)] << endl;
  }
}

void print(vector<string> img){ //debugging test
  for (int j=0; j<img.size(); j++){cout << img[j] << endl;}
  cout << "\n" << endl;
}

int main(){
  string s;
  ifstream dataFile("aoc22day10.txt");

  int cycle = 0;
  int X = 0;
  
  while (getline(dataFile, s)) {
    print(img);
    if (s=="noop"){cycle++; Draw(cycle, X);} //1 cycle and draw
    else {
      int AddNum = stoi(s.substr(5,s.length()-5));
      for (int i=0; i<2; i++){ //loop through 2 cycles
        cycle++; //add cycle
        Draw(cycle, X); //draw
      }
      X += AddNum;
    }
  }
  
  //print result
  for (int j=0; j<img.size(); j++){
    cout << img[j] << endl;
  }
}