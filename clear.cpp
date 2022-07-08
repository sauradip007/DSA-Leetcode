#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    vector<int>a{1,2,4,5,6};
    a.clear();
    a.push_back(7);
    a.push_back(6);
    a.push_back(5);
    a.push_back(4);
    a.push_back(8);
    int k = 3;
    vector<int>c{-1,-1,0,1,2,4};
    sort(c.begin(),c.end());
    for(int i = 0 ; i < a.size(); i++)
    {
        cout<<c[i]<<" ";
    }cout<<endl;
}