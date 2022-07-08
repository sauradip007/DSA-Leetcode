#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    //2nd approach
    string s = strs[0];
    //assuming first string in array of strings is lcp

    //iterating through the list
    for(int i = 1;  i < strs.size() ; i++)
    {
        while(strs[i].find(s) != 0) //if it is a prefix it appears in the starting of the string and find() should give 0 regardless of its size
        {
            s = s.substr(0,s.length()-1);
            //reducing the size of prefix by 1 from the rhs
        }
        //once it is found we make one last check
        if(s.length() == 0)
        {
            return "";
        }
    }
    return s;
}
//     string longestCommonPrefix(vector<string> &strs)
// {
//     // The idea is to sort the array of strings
//     // The first and last strings in the array will be the most different so the common prefix between them will be the common prefix for the entire array
//     sort(strs.begin(),strs.end());
//     string pref = "";
//     int maxCount = INT_MIN;
//     string longestPref = "";
//     string s = strs[0];
//     string t = strs[strs.size()-1];
//     int i  = 0;
//     int j = 0;
//     while(i < s.length() && j < t.length())
//     {
//         if(s[i] == t[i])
//         {
//             longestPref += s[i];
//             i++;
//             j++;
//             continue;
//         }
//         else
//         break;
        
//     }
  
//     return longestPref;
// }
    int main()
    {
        vector<string> a{"flight","flow","flower"};
        cout<<longestCommonPrefix(a)<<endl;
    }











