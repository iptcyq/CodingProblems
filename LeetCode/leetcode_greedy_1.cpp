#include<iostream>
using namespace std;

/*
https://leetcode.com/problems/assign-cookies/description/
*/

int findContentChildren(vector<int>& g, vector<int>& s) {
	if (g.empty()||s.empty()){return 0;}
	vector<int> sortG = g;
	vector<int> sortS = s;
	sort(sortG.begin(), sortG.end());
	sort(sortS.begin(), sortS.end());

	int count = 0;
	for (int i=0; i<sortS.size(); i++){
		if (sortS[i] >= sortG[i]){
			count++;
		}
		else{sortS.erase(sortS.begin() + i); i--;}
		if (i == sortG.size()-1){break;}
	}
	return count;
}