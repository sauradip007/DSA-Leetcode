#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
int reversepair(vector<int>&nums)
{
    vector<int>ans;
    int i = 0;
    int j = nums.size()-1;
    int pairs = 0;
    while(i < j)
    {
        sort(nums.begin(),nums.begin()+i+1);
        if(i < nums.size() && nums[i] <= 2*nums[i+1])
        {
            // No such pair will exist for that i
            continue;
        }
        else{
            pairs++;
            
        }
    }
}