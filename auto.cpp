#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> a(4,0);
    a[1] = 3;
    a[3] = 4;
    for( auto &itr : a )
    {
        cout<<itr<<" ";
    }cout<<endl;
}