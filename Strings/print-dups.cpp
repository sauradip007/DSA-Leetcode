#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
int main()
{
    string s = "geeksforgeeks";
    unordered_map<char,int>freq;
    for(int i = 0 ; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    // We need to print the characters that are duplicate

    // Traversing the hashmap
    unordered_map<char,int>::iterator it = freq.begin();
    while(it != freq.end())
    {
        if(it->second > 1)
        {
            cout<<"char : "<<it->first<<" "<<"count : "<<it->second<<endl;
            
        }
        it++;
    }cout<<endl;
    
}