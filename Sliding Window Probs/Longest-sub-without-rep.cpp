#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main()
{
    string s = "abcabcbb";
    int i = 0;
    int j = 0;
    int n = s.length();
    //condition->without repeating
    unordered_map<char,int>M;
    int mx = INT_MIN;
    while(j < n)
    {
        M[s[j]]++;
        // if(M[j] < 1)
        // {
        //     j++;
        //     continue;
        // }
        if(M[s[j]]==1)
        {
            //unique chars have been hit
            mx = max(j-i+1,mx);
            j++;
            continue;
        }
        else{
            while(M[s[j]] > 1 && i < n)
            {
                M[s[i]]--;
                if(M[s[i]] == 0)
                {
                    M.erase(s[i]);
                }
                i++;
            }
            j++;
            continue;
        }
    }
    cout<<"The longest sub is : "<<mx<<endl;
}