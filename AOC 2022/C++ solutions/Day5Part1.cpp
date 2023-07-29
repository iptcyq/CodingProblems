#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


int main(){
  //pre-processing
  string s;
  ifstream dataFile("aoc22day5.txt");
  vector<string> data;
  while (getline(dataFile, s)) {
    data.push_back(s);
  }

  //get all the containers in a list
  vector<vector<char>> container;
  for (int i=1; i<35; i+=4){ //i is horizontal stack number
    vector<char> tempCont;
    for (int j=8; j>=0; j--){ //j is vertical layer number
      if (isalpha(data[j][i])){
        tempCont.push_back(data[j][i]);
      }
    }
    container.push_back(tempCont);
  }


  //from line 11 on
  for (int k=10; k<511;k++){
    //extract the numbers into [move, from, to]
    string s = data[k];
    for (char& c : s){if (isalpha(c)){c = ' ';}}
    
    stringstream ss(s);
    int val;
    vector<int> numbers;
    while (ss >> val){
      numbers.push_back(val);
    }
    
    //store and move char
    for (int m=0; m<numbers[0]; m++){ //number of containers to move
      char moving = container[numbers[1]-1].back(); //store char
      container[numbers[1]-1].pop_back(); //delete char
      container[numbers[2]-1].push_back(moving); //add char
    }
  }

  //print final container layout
  for (const auto& row : container) {
    for (const auto& elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
  
}
