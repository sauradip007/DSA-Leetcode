#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
    vector<int>a{5,3,1,2};
    int sum = 0;
    for(auto &x:a)
    {
        sum += x;
    }
    cout<<sum<<endl;
}