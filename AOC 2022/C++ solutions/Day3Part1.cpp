#include <iostream> 
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  //pre-processng and init
  string s;
  ifstream dataFile("aoc22day3.txt");
  int prioritySum = 0;
  
  while (getline(dataFile, s)) { //every line is a new sack
    //split into two partitions
    string cont1 = s.substr(0, s.length()/2);
    string cont2 = s.substr(s.length()/2, s.length()/2); // second argument is length, not end index

    for (int item = 0; item < cont1.length(); item ++){
      char c = cont1[item];
      if (find(cont2.begin(), cont2.end(), c) != cont2.end()){ //found same item
        int ascii = c; //convert char to ascii value
        if (ascii>96){ //use ascii value to convert to relevant priority
          ascii -= 96;
        }
        else{
          ascii -= 38;
        }
        prioritySum += ascii; //add the ascii value
        break;
      }
    }
  }
  //print final total priority
  cout << prioritySum << endl;
}
