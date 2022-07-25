#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int binSearch(vector<int>& nums,int target)
{
    int start = 0;
    int end = nums.size()-1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int>&nums,int target)
{
    vector<int>ans;//contains ans
    //brute force
    int maxIndex = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > target)
        break;
        if(nums[i] == target && i > maxIndex)
        {
            ans.push_back(i);
            maxIndex = i;
            continue;
        }
    }

    //minimising array
    vector<int>res;
    // res.push_back(ans[0]);
    // res.push_back(ans[ans.size()-1]);
    if(ans.size() == 0)
    {
        //if ans is empty until now , no occurence of element exists
        ans.push_back(-1);
        ans.push_back(-1);
    }
    if(ans.size() == 1)
    {
        //only one occurence of element
        ans.push_back(ans[0]);
    }
    return {ans[0],ans[ans.size()-1]};

}
// vector<int> searchRange_2(vector<int>&nums,int target)
// {
//     //trying 2 binary searches
//     int start = 0;
//     int end = nums.size()-1;
//     vector<int>res;
//     int maxIndex = INT_MIN;
//     while(start <= end)
//     {
//         int mid = (start + end)/2;
//         if(nums[mid] == target)
//         {
//             res.push_back(mid);
//             //conducting bsearch here
//             int s1 = mid-1;
//             int e1 = mid+1;





//             // 2 possibilities , either next occurence is to right, to left or that element itself
//             // if(mid+1 < nums.size() && nums[mid+1] == target)
//             // {
//             //     int maxIndex = mid+1;
//             //     while(nums[maxIndex+1] == target && maxIndex+1 < nums.size())
//             //     {
//             //         maxIndex++;
//             //     }
//             //     res.push_back(maxIndex);
//             //     break;
//             // }
//             // if(mid-1 >= 0 && nums[mid-1] == target)
//             // {
//             //     int maxIndex = mid-1;
//             //     while(nums[maxIndex-1] == target && maxIndex-1 >= 0)
//             //     {
//             //         maxIndex--;
//             //     }
//             //     res.push_back(maxIndex);
//             //     break;
//             // }
//             // res.push_back(mid);
//             // break;
            
//         }
//         else if(nums[mid] > target)
//         {
//             end = mid-1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//     }
//     if(res.size() == 0)
//     {
//         res.push_back(-1);
//         res.push_back(-1);
//     }
//     sort(res.begin(),res.end());
//     return res;

// }
vector<int>searchRange_3(vector<int>&nums,int target)
{
    int start = 0;
    int end = nums.size()-1;
    int res = -1;
    vector<int>ans;
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(nums[mid] == target)
        {
            res = mid;
            end = mid-1;

        }
        else if (nums[mid] > target)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    ans.push_back(res);
    res = -1;
    //may be the first occ
    // searching for first occ in left half
    start = 0;end = nums.size()-1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    ans.push_back(res);
    return ans;
}
int main()
{
    vector<int> a{2,4,10,10,10,18,20};
    vector<int>b = searchRange_3(a,10);
    for(int i = 0 ; i < b.size(); i++)
    {
        cout<<b[i]<<" ";
    }cout<<endl;
}