#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    unordered_map<int,int>ourMap;
    for(int i = 0 ; i < nums.size(); i++)
    {
        ourMap[nums[i]]++;
    }
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(ourMap[nums[i]] > 1)
        {
            return nums[i];
        }
    }
    return -1;//no duplicates
}
int main()
{
    vector<int>a{2,2,2,2,2};
    cout<<findDuplicate(a)<<endl;
}