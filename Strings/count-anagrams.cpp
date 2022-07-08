
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int countOccurance(string s, string p)
{
    
    unordered_map<char, int> mp;
    int ans = 0;

    // storing the occ. of string p in the map
    for (int x = 0 ; x < p.size(); x++)
    {
        mp[p[x]]++;
    }

    int count = mp.size();
    int k = p.size();
    int i = 0, j = 0;
   
    vector<string>anagram;
    while (j < s.length())
    {
        // calculation part
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        // window length not achived yet
        if (j - i + 1 < k)
        {
            j++;
        }

        // window length achived, find ans and slide the window
        else if (j - i + 1 == k)
        {
            // finding the ans
            if (count == 0)
            {
                ans++;
                
            }
           
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                {
                    count++;
                }
            }

            // slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
  string s = "";
  string t = "";

    cout << countOccurance(s, t) << "\n";
    return 0;
}