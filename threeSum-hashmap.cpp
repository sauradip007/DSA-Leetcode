#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    if(nums.size() < 3)
    {
        return ans;
    }
    if(nums[0] > 0)
    {
        return ans;
    }
    unordered_map<int,int>hashMap;
    //hashmap stores last occurence of every element
    for(int i = 0 ; i < nums.size() ; i++)
    {
        hashMap[nums[i]] = i;
    }

    // Traversing loop
    for(int i = 0; i < nums.size() - 2 ; i++)
    {
        if(nums[0] > 0)
        {
            return ans;
        }
        for(int j = i+1 ; j < nums.size() - 1; j++)
        {
            int req = (-1)*(nums[i] + nums[j]);
            if(hashMap.count(req) && hashMap.find(req) != hashMap.end() && hashMap.find(req)->second > j )
            {
                ans.push_back({nums[i], nums[j], req});

               

            }
            // Updating j to last index avoid dups
            j = hashMap.find(nums[j])->second;
        }
        // Similarly for i
        i = hashMap.find(nums[i])->second;
    }
    return ans;
}
int main()
{
    vector<vector<int>> ans;
    vector<int> a{1, 0, -1, 2, -1, -4};
    ans = threeSum(a);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}