#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// Brute force
int countPrefixe(vector<string> &words, string s)
{
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].size() > s.size())
            continue;
        bool flag = true;
        for (int j = 0; j < words[i].size(); j++)
        {
            if (words[i][j] != s[j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            ans++;
    }
    return ans;
}
int countPrefixes(vector<string> &words, string s)
{
    int n = words.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string str = words[i];
        if (str == s.substr(0, str.size()))
            cnt++;
    }
    return cnt;
}
int main()
{
    vector<string> a{"a","abc","b","c","bc","ab","ac"};
    string s = "abc";
    cout<<countPrefixe(a,s)<<endl;
}