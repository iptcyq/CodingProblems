#include <iostream> 
#include <fstream>
#include <algorithm>
using namespace  std;

int main() {
  #pre-processing and init
  string s;
  char ref[] = {'X','A','Y','B','Z','C'};
  int points = 0;
  ifstream dataFile("aoc22day2.txt");
  
  //still incomplete due to incorrect answer
  while (getline(dataFile, s)) {//each line is a new round
    char opp, plyr = s[0], s[2]; //label char and index of value in ref array
    auto it = find(begin(ref),end(ref),opp); 
    int o = it - begin(ref);
    it = find(begin(ref),end(ref),plyr);
    int p = it - begin(ref);

    //mild bruteforce method
    if (o==5 && p==0){ //edge winning case if input is last and first value
      points += 6;
    }
    else if (p-o==1){ //win condition (according to ref array)
      points += 6;
    }
    else if (o-p==1){ //draw condition
      points += 3;
    }
    //otherwise will be a loss (0 points) - no change

    if (p==0){ //if rock
      points += 1;
    }
    else if (p==2){ //if paper
      points += 2;
    }
    else{ //otherwise is scissors
      points += 3;
    }
  }

  //print final points
  cout << points << endl;
}

