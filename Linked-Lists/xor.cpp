#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include <map>
using namespace std;
int missingNumber(vector<int> &nums)
{                             // function to return missing number
    int result = nums.size(); // initialize result to size of vector
    int i = 0;                // initialize i to 0
    for (int num:nums)
    {                  // for each number in vector
        result ^= num; // XOR result with number
        result ^= i;   // XOR result with i
        i++;           // increment i
    }
    return result; // return result that is the missing number
}
vector<int> missingNum(vector<int> &nums)
{                             // function to return missing number
    int result = nums.size(); // initialize result to size of vector
    int j = 0;
    int sum_arr = 0;               // initialize i to 0
    // for (int num : nums)
    // {        
    //     sum_arr += num;          // for each number in vector
    //     result ^= num; // XOR result with number
    //     result ^= i;   // XOR result with i
    //     i++;           // increment i
    // }

    for(int i = 0 ; i < nums.size(); i++)
    {
        sum_arr += nums[i];
        result ^= nums[i];
        result ^= j;
        j++;
    }
    cout<<result<<endl;
    //result is the missing no in the [0,n] interval
    int n = nums.size();
    nums.clear();
    nums.push_back(result);
    int missing_second = ((n+1)*(n+2)/2) - (sum_arr + result);//(n+1)*(n+2)/2 is the sum of numbers from 0 to n+1
    nums.push_back(missing_second);
    return nums; // return result that is the missing number
}
int main()
{
   int res = 4;
   res ^= 4;
   cout<<res<<endl;
    vector<int>a{4,0,3,1,2};
    vector<int>b = missingNum(a);
    // cout<<missingNumber(a)<<endl;
    for(int i = 0 ; i < b.size(); i++)
    {
        cout<<b[i]<<" ";
    }cout<<endl;
}