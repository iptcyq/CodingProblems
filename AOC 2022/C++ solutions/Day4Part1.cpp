#include<iostream>
#include <fstream>
using namespace std;

int main(){
  string s;
  ifstream dataFile("aoc22day4.txt");
  int counter = 0;
  
  //also incomplete as I'm randomly having stoi errors in the middle of going through the data
  while (getline(dataFile, s)) {
    //every new pair per line
    int i = s.find(','); 
    int j = s.substr(0,i).find('-');
    int elf1[] = {stoi(s.substr(0,j)), stoi(s.substr(j+1,i))};
    
    j = s.substr(i+1,s.length()).find('-');
    int elf2[] = {stoi(s.substr(i+1,j)), stoi(s.substr(j+1,s.length()))};

    //cout <<elf1[0]<<"   "<<elf1[1]<<endl;
    //cout <<elf2[0]<<"   "<<elf2[1]<<endl;
    
    if (elf1[0]<=elf2[0]){ //elf1 potentially fully contains elf2
      if (elf1[1]>=elf2[1]){
        //fully contains 
        counter += 1;
        //cout << elf1<<elf2<<endl;
      }
    }
    else if (elf2[0]<=elf1[0]){ //elf2 might fully contain elf1
      if (elf2[1]>=elf1[1]){
        //fully contains
        counter += 1;
        //cout << elf2<<elf1 <<endl;
      }
    }
    
  }
  cout << counter << endl;

}