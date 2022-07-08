// simple technique that allows to perform fast calculation on the sum of elements in a given range(contiguous elements)

// So say there is an array 6 3 -2 4 -1 0 -5
// The prefix sum array would look like: 6 9 7 11 10 10 5
// So basically we are adding the previous element + current element you are in within the array
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
int subarraydivK(vector<int>&nums, int k)
{
    vector<int>counts(k,0);
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += (nums[i] % k) % k;
        counts [sum % k]++;
    }
    int result = 0;
    for(auto& it : counts)
    {
        result += (it*(it-1))/2;

    }
    return result;
}

int main()
{
    vector<int> a {4,5,0,-2,-3,1};
    cout<<subarraydivK(a,5)<<endl;
}