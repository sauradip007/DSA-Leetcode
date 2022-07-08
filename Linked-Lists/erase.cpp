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
int main()
{
    vector<int>a{1,3,5,2,4};
    a.erase(a.begin());
    a.erase(a.begin());
    for(int i = 0 ; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}