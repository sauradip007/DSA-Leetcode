#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include<math.h>
using namespace std;
int mini(vector<int>&nums)
{
    int mins = INT_MAX;
    for(int i = 0; i < nums.size(); i++)
    {
        mins = min(nums[i],mins);
    }
    return mins;
}
int secondMini(vector<int>&nums)
{
    int mins = mini(nums);
    int second = INT_MAX;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > mins)
        {
            second = min(nums[i],second);
        }

    }
    if(second == INT_MAX)
    {
        return nums[0];
    }
    else
    return second;
}
int minimumMoves(vector<int>&nums)
{
    int count = 0;

    int indexMin = 0;
    int secondindMin = 0;
    for (int i = 0; i <= 5; i++)
    {
        int minimum = mini(nums);
        int secondMinimum = secondMini(nums);
  
        sort(nums.begin(), nums.end());

        nums[0] = nums[0] + 1;
        nums[1] = nums[1] + 1;
        count++;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum == n * nums[0])
        {
           return count;
        }

        continue;
    }
   return count;
    // unordered_map<int,int>M;
    // for(int i = 0 ; i < nums.size(); i++)
    // {
    //     M[nums[i]]++;
    // }
    // int count = 0;

    // int indexMin = 0;
    // int secondindMin = 0;
    // for(int i  = 0 ; i <= 5;i++)
    // {
    //     int minimum = mini(nums);
    //     int secondMinimum = secondMini(nums);
    //     cout<<minimum<<" "<<secondMinimum<<endl;
    //     for(int j = 0 ; j < nums.size(); j++)
    //     {
          
    //         if(nums[j] == minimum)
    //         {
    //             indexMin = j;
    //         }
    //         if(nums[j] == secondMinimum)
    //         {
    //             secondindMin = j;
    //         }
            
    //     }
    //     cout<<indexMin<<" "<<secondindMin<<endl;
    //     // they will be reduced by 1
    //     nums[indexMin] = nums[indexMin] + 1;
    //     nums[secondindMin] = nums[secondindMin]+1;
    //     count++;

    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i = 0 ; i < n; i++)
    //     {
    //         sum += nums[i];
    //     }
    //     if(sum == n*nums[0])
    //     {
    //         return count;
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout<<nums[i]<<" ";
    //     }cout<<endl;
    //     continue;
    // }
    // return count;
}

int main()
{
    vector<int>nums{4,5,6};
    int mins = mini(nums);
    int ans = 0;
    for(int i = 0 ; i < nums.size(); i++)
    {
        ans += nums[i];
    }
    cout<<ans - (nums.size()*mins)<<endl;
}