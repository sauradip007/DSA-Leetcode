#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
bool isAnagram(string s, string p)
{
    unordered_map<char, int> mp;
    int ans = 0;

    // storing the occ. of string p in the map
    for (int x = 0; x < p.size(); x++)
    {
        mp[p[x]]++;
    }

    int count = mp.size();
    int k = p.size();
    int i = 0, j = 0;

    vector<string> anagram;
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
                return true;//anagram found
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
    return false;
}
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     //maintain a hashmap so similar anagram entries dont get counted within your answer
//     unordered_map<string,bool>ourMap;
//     vector<vector<string>>ans;
//     sort(strs.begin(), strs.end());
//     for(int i = 0 ; i < strs.size()-1; i++)
//     {
//         if(ourMap[strs[i]])
//         {
//             continue;
//         }
       
//         vector<string>res;
//         string str = strs[i];
//         // res.push_back(str);
//         // ourMap[str] = true;
//         int j = i+1;
        
        
//     }
//     return ans;

// }
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string,vector<string>>M;
    vector<vector<string>>ans;
    for(int i = 0 ; i < strs.size(); i++)
    {
        string str = strs[i];
        //sorting
        sort(strs[i].begin(),strs[i].end());
        M[strs[i]].push_back(str);
        
    }
    for(auto i:M)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    // string s = "tea";
    // string t = "eat";
    // cout<<isAnagram(s,t)<<endl;
    vector<string>a{"eat","tea","tan","ate","nat","bat"};
    sort(a[0].begin(),a[0].end());
    for(int i = 0 ; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
// maintain a hashmap so similar anagram entries dont get counted within your answer
// unordered_map<string, bool> ourMap;
// vector<vector<string>> ans;
// for (int i = 0; i < strs.size(); i++)
// {
//     if (ourMap[strs[i]])
//     {
//         continue;
//     }
//     vector<string> res;
//     string str = strs[i];
//     res.push_back(str);
//     ourMap[str] = true;
//     for (int j = 0; j < strs.size(); j++)
//     {
//         if (i == j)
//             continue;
//         if (str == "" && strs[j] == "")
//         {
//             res.push_back(strs[j]);
//             ourMap[strs[j]] = true;
//         }
//         if (isAnagram(str, strs[j]))
//         {
//             res.push_back(strs[j]);
//             ourMap[strs[j]] = true;
//         }
//     }
//     ans.push_back(res);
//     res.clear();
// }
// return ans;