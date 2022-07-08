#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
// int subarraySum(vector<int> &nums, int x)
// {
//     int count = 0;
//     for(int i = 0 ; i < nums.size(); i++)
//     {
//         for(int j = i; j < nums.size(); j++)
//         {
         
//             int sum = 0;
//             for(int k = i ; k <= j ; k++)
//             {
//                 sum += nums[k];
              
//             }
//             if (sum == x)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
int subarraySum(vector<int> &nums,int k)
{
    
int n = nums.size();
if( n == 0 )
return 0; //no such subarray

unordered_map<int,int>ourMap;
int currSum  = 0;//keeps track of current sum
int count = 0;//keeps track of no of subarrays
int i = 0;
while(i < n)
{
    currSum += nums[i];
    if(currSum == k) //if equal
    {
        count++;
    }
   
       if(ourMap.find(currSum - k) != ourMap.end())
       {
           
           count += ourMap[currSum-k];
       }

       ourMap[currSum]++;
       i++;
    
}
return count;
   
    
}
int main()
{
    vector<int>n{1,1,1};
    cout<<subarraySum(n,2)<<endl;
}