#include <iostream> 
#include <fstream>
#include <string.h>
using namespace  std;

int main() {
  //input pre-processing
  int totalCal = 0;
  int mostCal = 0;
  string s;
  ifstream dataFile("aoc22day1.txt");
  
  while (getline(dataFile, s)) {
    // Unsure of what the empty line is so I have to check it this way
    if (s.empty() || !s.find_first_not_of("0123456789")){ //empty line = new elf
      if (totalCal>mostCal){ //if current elf has more calories than the most, change
        mostCal = totalCal;
        totalCal = 0;
      }
    }
    else{ //otherwise add more calories to the current elf
      int cal = stoi(s);
      totalCal += cal;
    }
  }
  
  //print the results
  cout << mostCal<<endl;
}

