#include<iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

/*
Note: modified the input data slightly too
Error: Fails to work at round 7, where the stoi function doesn't work, tried debugging but can't find the reason yet
*/

int main(){
  string s;
  ifstream dataFile("aoc22day11.txt");
  vector<string> data;
  while (getline(dataFile, s)) {
    data.push_back(s);
  }
  int businessCounter[] = {0,0,0,0,0,0,0,0}; //counter storage for monkey business
  
  for (int i=0; i<20; i++){ //20 rounds
    for (int j=0; j<data.size(); j+=6){ //rotate through the 8 monkeys
      //inspect item - get worry level
      char s[data.size()+1];
      strcpy(s, data[j].c_str());
      char *ptr;   
      ptr = strtok(s, " , ");   
      while (ptr != NULL)  
      {  
        cout << ptr  << " ";  
        int worry = stoi(ptr); //convert to worry level
        businessCounter[j/6] += 1; //add 1 to counter when inspecting
		
        //modify worry level according to the equation
        if (data[j+1][0] == '+'){worry+=stoi(data[j+1].substr(1,3));} 
        else if (data[j+1][0] == '*'){worry*=stoi(data[j+1].substr(1,3));} 
        else if (data[j+1][0] == '^'){worry=worry*worry;} 
        worry=floor(worry/3); //divide worry level by 3

        //cout << worry << " ";
		
        //check if worry level meets condition
        if (worry%stoi(data[j+2].substr(13,3))==0){ //true
          //throw to monkey under true
          data[1+stoi(data[j+3].substr(16,3))] += ", " + to_string(worry);
          //cout << data[j+3].substr(16,3) << endl;
        }
        else{ //false
		  //throw to monkey under false
          data[1+stoi(data[j+4].substr(16,3))] += ", " + to_string(worry);
          //cout << data[j+4].substr(16,3) << endl;
        }
        ptr = strtok (NULL, " , ");
        //cout << "monkey ended " << j << endl;
      }
      //data[j] = "";
    }
    cout << "round ended " << i << endl;
    for (int l=0; l<8; l++){cout << businessCounter[l] << " ";} //print business counter after every round 
    cout << "\n" << endl;
  }
  
}