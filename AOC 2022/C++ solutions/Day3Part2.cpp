#include <iostream> 
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  //pre-processing
  string s;
  ifstream dataFile("aoc22day3.txt");
  int prioritySum = 0;

  string sack1 = "";
  string sack2 = "";
  string sack3 = "";
  
  while (getline(dataFile, s)) {
    //grouping the strings into relevant sacks
    if (sack1==""){
        sack1 = s;
    }
    else if (sack2==""){
      sack2 = s;
    }
    else{
      sack3 = s;

      for(int item=0; item<sack1.length();item++){
        char c = sack1[item]; //defining the potentially common character

        //finding a match with both sacks
        if (find(sack2.begin(),sack2.end(),c)!=sack2.end() &&
          find(sack3.begin(),sack3.end(),c)!=sack3.end()){

          //converting to priority number
          int ascii=c;
          if (ascii>96){
            ascii -= 96;
          }
          else{
            ascii -= 38;
          };
          
          //summing the numbers
          prioritySum += ascii;
          break;
        }
      }
      //resetting after every group
      sack1= "";
      sack2 ="";
      sack3 = "";
    }
  }

  //print results
  cout << prioritySum << endl;
}
