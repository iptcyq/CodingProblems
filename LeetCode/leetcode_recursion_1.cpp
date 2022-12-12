#include<iostream>
using namespace std;

/*
https://leetcode.com/problems/n-th-tribonacci-number/description/
*/

int tribonacci(int n) {
    if (n==0) {return 0};
    else if (n<=2) {return 1};
    vector<int> nums = {0,1,1};
    for (int i=3; i<=n; i++){
        int number = 0;
        for (int j=0; j<3; j++){
            number += nums[j];
        }
        nums.erase(nums.begin());
        nums.push_back(number);
    }
    return nums[2];
}