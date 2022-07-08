
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    // Sort the array
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    // if the array size is less than 3 return ans
    if (nums.size() < 3)
    {
        return ans;
    }
    // if first element of sorted array is +ve return ans
    if (nums[0] > target)
    {
        return ans;
    }
    // entering for loop
    for (int i = 0; i < nums.size(); i++)
    {
        // again if first element of subarray is +ve no more triplets are to be found
        if (nums[i] > target)
        {
            return ans;
        }
        // if one element of array is done being considered we need not check for dups
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int low = i + 1;
        int high = nums.size() - 1;
        int sum = 0;
        // entering while loop
        while (low < high)
        {
            sum = nums[i] + nums[low] + nums[high];
            if (sum > target)
            {
                high--;
            }
            else if (sum < target)
            {
                low++;
            }
            // Case where triplet is found
            else
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                int last_occurence_low = nums[low]; // in the sub array we mark the last low element(we dont want thay duplicate)
                // similarly for high
                int last_occurence_high = nums[high];
                // we update last occurence to be unique accordingly
                while (low < high && last_occurence_low == nums[low])
                {
                    low++;
                }
                // similarly for high
                while (low < high && last_occurence_high == nums[high])
                {
                    high--;
                }
            }
        }
    }
  return ans;
}

 vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>>ans;
    if(nums.size() == 0)
    return ans;
    sort(nums.begin(),nums.end());
    if(nums[0] > target)
    return ans;
    if(nums.size() < 4)
    return ans;
    // 2 loops
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j < nums.size() ; j++)
        {
            int front = j+1;
            int back = nums.size()-1;
            // Now conduct 2 Sum approach
            int req = target - (nums[i]+nums[j]);
            while(front < back)
            {
                if(nums[front] + nums[back] > req)
                {
                    back--;
                }
                else if(nums[front] + nums[back] < req)
                {
                    front++;
                }
                else{
                    // push the quadruplet
                    ans.push_back({nums[i],nums[j],nums[front],nums[back]});
                    // creating a 4 element vector and initialising it with 0 
                    vector<int>quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[front];
                    quad[3] = nums[back];
                    while(front < back && quad[2] == nums[front])
                    {
                        front++;
                    }
                    // Avoid dups
                    while(front < back && quad[3] == nums[back])
                    {
                        back--;
                    }
                }
                // Now we avoid dups for j as well
                while(j+1 < nums.size() && nums[j+1] == nums[j])
                {
                    j++;
                }
            }
        }
    }
    return ans;

 }
    

