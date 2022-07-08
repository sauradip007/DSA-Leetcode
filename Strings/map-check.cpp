
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
    string s = "abba";
    unordered_map<char,int>freq;
    for(auto &x : s)
    {
        freq[x]++;

    }
    cout<<freq[s[0]]<<endl;
    cout<<freq.size()<<endl;
    // cout<<freq.find(2)->second<<endl;
}