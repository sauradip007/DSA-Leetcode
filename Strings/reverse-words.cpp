
#include <iostream>
#include <cstring>
#include<algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
string reverseWord(string s)
{
    if(s.length() == 0)
    return s;

    int j = 0;
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] != ' ')
        {
           j = i;
        }
        while(s[j] != ' ' && j < s.length())
        {
            j++;
        }
        reverse(s.begin() + i, s.begin() + j);
        i = j;

    }
    return s;
}
    string reverseWords(string s)
    {
        // s = 'God Ding' output = 'doG gniD'
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                j = i;
            }
            else
                continue;
            while (j < s.length() && s[j] != ' ')
            {
                j++;
            }
            reverse(s.begin() + i, s.begin() + (j));
            i = j;
        }
        return s;
    }
    int main()
    {
        string s = "God Ding";
        string t = reverseWord(s);
        cout << t << endl;
    }