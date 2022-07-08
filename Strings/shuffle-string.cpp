#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string restoreString(string s, vector<int>& indices) {
    string store;
    // store = s;
    // s.clear();
    // s=(empty) indices = 45670123

    for(int i = 0 ; i < indices.size() ; i++)
    {
       store.push_back(s[indices[i]]);
    }
    return store;
}
int main()
{
    string a = "codeleet";
    vector<int>indices{4,5,6,7,0,2,1,3};
    cout<<restoreString(a,indices)<<endl;
}