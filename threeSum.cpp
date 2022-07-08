#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    // Sort the array
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    //if the array size is less than 3 return ans
    if(nums.size() < 3)
    {
        return ans;
    }
    //if first element of sorted array is +ve return ans
    if(nums[0] > 0)
    {
        return ans;
    }
    //entering for loop
    for(int i = 0 ; i < nums.size() ; i++)
    {
        // again if first element of subarray is +ve no more triplets are to be found
        if (nums[i] > 0)
        {
            return ans;
        }
        //if one element of array is done being considered we need not check for dups
        if(i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        int low = i+1;int high = nums.size() - 1;
        int sum = 0;
        //entering while loop
        while(low < high)
        {
            sum = nums[i] + nums[low] + nums[high];
            if(sum > 0)
            {
                high--;
            }
            else if(sum < 0)
            {
                low++;
            }
            // Case where triplet is found
            else{
                ans.push_back({nums[i],nums[low],nums[high]});
                int last_occurence_low = nums[low]; //in the sub array we mark the last low element(we dont want thay duplicate)
                // similarly for high
                int last_occurence_high = nums[high];
                //we update last occurence to be unique accordingly
                while(low < high && last_occurence_low == nums[low])
                {
                    low++;
                }
                // similarly for high
                while(low < high && last_occurence_high == nums[high])
                {
                    high--;
                }
            }
        }
      
       
    }
    return ans;
    
}
int main()
{
    vector<vector<int>> ans;
    vector<int> a { 1, 0, -1, 2, -1, -4 };
    ans = threeSum(a);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0 ; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

}