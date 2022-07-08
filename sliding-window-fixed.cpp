#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
int main()
{
    int k = 3;
    vector<int>a {2,3,5,2,9,7,1};
    int sum  = 0;
    int maxSum = INT_MIN;
    for(int i = 0 ; i <= a.size()-k; i++)
    {
        sum = 0;
        for(int j = i; j < k+i;j++)
        {
           sum += a[j];
        }
        maxSum = max(sum,maxSum);
    }
    cout<<maxSum<<endl;
}