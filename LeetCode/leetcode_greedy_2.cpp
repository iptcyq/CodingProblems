#include<iostream>
using namespace std;

/*
https://leetcode.com/problems/can-place-flowers/description/
*/

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	vector<int> tempBed = flowerbed;
	bool prevEmpty = true;
	for (int i=0; i<tempBed.size(); i++){
		if (tempBed[i]==1){
			if (prevEmpty==false){ n++; } //remove accidental addition
			prevEmpty = false;
		} //not empty
		else if (prevEmpty == true){n--; prevEmpty=false;} //has space to put
		else {prevEmpty = true;} //currently empty,but previous isnt
	}
	return (n<=0);
}