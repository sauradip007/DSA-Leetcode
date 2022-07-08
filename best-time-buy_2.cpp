#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int maxProfit (vector<int>&nums)
{
    int profit = 0;
    for(int i = 1 ; i < nums.size(); i++)
    {
        if(nums[i] > nums[i-1])
        {
            profit += nums[i] - nums[i-1];
        }

    }
    return profit;
}
int main()
{
    vector<int> a{7, 1, 5, 3, 6, 4};
    // vector<int> diff;
    // int maxProfit = 0;
    // // Find local minima
    // int max_occ = INT_MIN;
    // for (int i = 1; i < a.size()-1; i++)
    // {
    // //   if(a[0] > a[1])
    // //   {
    // //       continue;
    // //   }

    //   if(a[i] > a[i-1] && a[i] > a[i+1])
    //   {
    //       int j = i;
    //       int  k = a[i];
    //       while(j < a.size())
    //       {
             
    //           max_occ = max(a[j],k);
    //         //   k = max_occ;
    //           j++;
    //       }

    //       maxProfit += max_occ - a[i]; 
    //   }
    //   else
    //   continue;
    // }
  cout<<maxProfit(a)<<endl;
}