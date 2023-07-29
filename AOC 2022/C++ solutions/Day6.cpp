#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  string s;
  ifstream dataFile("aoc22day6.txt");
  string code;
  while (getline(dataFile, s)) {
    code = s;
  }

  string marker;
  for (int i=0; i<s.length(); i++){ //for every character in the string
    int index = marker.find(code[i]); //find the index
    if (index < marker.length()){
      //contains the character, reset up till character
      marker = marker.substr(index+1, (marker.length() - index));
    }

    marker += code[i]; //add new character
    if (marker.length() >= 4){ //once a marker is formed
      cout << "At index " << i+1 << endl; //print and exit
      break;

      /*
        Similar for part 2, 
        just to change break to be at marker.length() == 14
      */
    }
  }
}