#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
vector<int>v;
vector<vector<int>>ans;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.push_back(6);
v.push_back(7);
v.push_back(8);

ans.push_back({v[0],v[1],v[2]});
ans.push_back({v[1],v[3],v[4]});
for(int i = 0 ; i < ans.size(); i++)
{
    for(int j = 0 ; j < ans[i].size(); j++)
    {
        cout<<ans[i][j]<<" ";
    }cout<<endl;
}
}