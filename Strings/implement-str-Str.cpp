#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// Using KMP
int strStr(string haystack, string needle){
    if (needle == "")
        return 0;

    if (needle.length() > haystack.length())
        return -1;
    
    vector<int>LPS(needle.length());
    int prevLPS = 0;
    int i = 1;
    while(i < needle.length())
    {
        if(needle[i] == needle[prevLPS])
        {
            LPS[i] = prevLPS+1;
            prevLPS++;
            i++;
        }
    }

}
int strStr(string haystack, string needle)
{
    // Naive approach
    int n = haystack.size();
    int m = needle.size();
    for(int i = 0 ; i <= n-m ; i++)
    {
        bool flag = true;
        for(int j = 0 ; j < m; j++)
        {
            if(needle[j] != haystack[i+j])
            flag = false;
            break;
        }
        if(flag)
        return true;
    }
    return false;
}
int strStr(string haystack, string needle)
{
    if(needle == "")
    return 0;
    if(needle.length() > haystack.length())
    return 0;

    int i = 0;
    int j = 0;
    int index = 0;
    bool flag = true;
    while(j < haystack.length() && i < needle.length())
    {
        if(needle[i] == haystack[j])
        {
            flag = true;
            index = j-i;
            
        }
        else{
            flag = false;
            j++;
            continue;
        }
        i++;
        j++;
    }
    if(flag)
    return index;
    else
    return -1;
}
int main()
{
    cout<<strStr("hello","ll")<<endl;
}