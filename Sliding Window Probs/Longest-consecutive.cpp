#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
int longestSub(vector<int>&nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, int> M;
    for (int i = 0; i < nums.size(); i++)
    {
        M[nums[i]]++;
    }
    int currCount = 1;
    int mx = INT_MIN;
    for (int i = 0; i < nums.size()-1; i++)
    {
        if(nums[i+1]-nums[i] == 1)
        {
            currCount++;
        }
        else{
            //store ans
            mx = max(currCount,mx);
            currCount = 1;
        }
    }
    return mx;
}
int main()
{
    vector<int> a{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestSub(a) << endl;
    // for(int n:a)
    // cout<<n<<" ";
    
}