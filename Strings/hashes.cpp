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
    string s = "abbf";
    unordered_map<char,int>M;
    for(int i = 0 ; i < s.length() ; i++)
    {
        M[s[i]]++;
    }

    unordered_map<char,int>::iterator it = M.begin();
    while(it != M.end())
    {
        cout<<it->second<<" ";
        it++;
    }cout<<endl;
    cout<<"The size is : "<<M.size()<<endl;
    cout<<M.find('b')->second<<endl;
}