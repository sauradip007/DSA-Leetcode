#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<unordered_map>
using namespace std;
// int subarraysDivByK(vector<int> &nums, int k)
// {
//     // Brute force O(n^3)
//     int count = 0;
//     for(int i = 0; i < nums.size() ; i++)
//     {
//         for(int j = i ; j < nums.size(); j++)
//         {
//             int sum = 0;
//             for(int l = i; l <= j ; l++)
//             {
//                 sum += nums[l];
//             }
//             if(sum % k == 0)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
//     // 38 out of 73 passed
// }
int subarraysDivByK(vector<int> &nums, int k)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int count = 0;
    unordered_map<int, int> ourMap;
    int i = 0;
    int currSum = 0;
    ourMap[currSum]++;
    while (i < nums.size())
    {
        currSum += nums[i];
        int rem = 0;
        rem = currSum % k;
        if (rem < 0)
            rem += k;

        if (ourMap.find(rem) != ourMap.end())
        {
            count += ourMap[rem];
        }
        ourMap[rem]++;
        i++;
    }
    return count;
}
    int main()
    {
        vector<int> a{4, 5, 0, -2, -3, 1};
        cout << subarraysDivByK(a, 5) << endl;
    }