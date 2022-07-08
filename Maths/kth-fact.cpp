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

int kthFactor(int n, int k)
{
    vector<int>factors;
    for(int i = 1 ; i <= n ; i++)
    {
        if(n % i == 0)
        {
            factors.push_back(i);
        }
    }

    // for(int i = 0 ; i < factors.size(); i++)
    // {
    //     cout<<factors[i]<<" ";
    // }cout<<endl;

    return factors[k-1];
}
int main()
{
    cout<<kthFactor(12,3)<<endl;
}