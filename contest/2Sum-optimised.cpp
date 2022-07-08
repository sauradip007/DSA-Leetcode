#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
vector<int>twosums(vector<int>&nums,int target)
{
    int i = 0;
    unordered_map<int,int>M;
    int n = nums.size();
    vector<int>ans;
    while(i < n)
    {
        
        if(M.find(target-nums[i]) != M.end())
        {
            //found
            ans.push_back(nums[i]);
            ans.push_back(target-nums[i]);
            return ans;

        }
        else{
            M[nums[i]]++;
        }
        i++;
    }
    return ans;
}
vector<int> twoSum(vector<int>& nums, int target){

    vector<int> ans;

    int n = nums.size();
    if (n == 0)
        return ans;
   
    unordered_map<int, int> ourMap;
    for (int i = 0; i < n; i++)
    {
       
        int req = target - nums[i];
      
        if (ourMap.find(req) != ourMap.end())
        {
            // cout<<ourMap.find(2)->second<<endl;
            ans.push_back(ourMap.find(req)->second);
            
            ans.push_back(i);
   
            return ans;
        }
        else{
            ourMap[nums[i]] = i;
        }
    }
    return ans;
}
int main()
{
    vector<int>a{3,2,4};
    vector<int>res = twosums(a,6);
    for(int i = 0 ; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }cout<<endl;
}