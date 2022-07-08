#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
bool checks(string s, string t)
{

    for (int i = 0; i < t.length(); i++)
    {
        //    flag = false;
        if (s.find(t[i]) >= 0 && s.find(t[i]) <= s.length() - 1)
        {

            continue;
        }
        else
            return false;
    }
    return true;
}
string checker(string s,string p)
{
    unordered_map<char, int> pat;
    // first we traverse p and populate the map with its frequency
    for (int i = 0; i < p.length(); i++)
    {
        pat[p[i]]++;
    }
    string res = ""; // smallest window substring
    // Now we find the minimum string where all chars of p are present in s
    int count = pat.size(); // no of distinct chars in p
    for (int i = 0; i < s.length(); i++)
    {
        res += s[i];
        if (pat.find(s[i]) != pat.end())
        {

            pat[s[i]]--;
            count--;
            if (pat[s[i]] < 0)
            {
                count++;
                // encorporated dups
            }
        }
        if (count == 0) // all chars are found up untill now
        {
            return res;
            
        }
    }
    for(int i = 0 ; i < p.length(); i++)
    {
        pat[p[i]] = 0;
    }
    if(checks(res,p))
    return res;
    else
    return "";
}
string smallestwind(string s, string p)
{
    unordered_map<char, int> pat;

    if (p.length() == 0)
    {
        return "";
    }
    // first we traverse p and populate the map with its frequency
    for (int i = 0; i < p.length(); i++)
    {
        pat[p[i]]++;
    }
    string res = "";
    vector<string>finalArr;

    for(int i = 0 ; i < s.length(); i++)
    {
        res = checker(s.substr(i),p);
        if(res == "")
        continue;
       
        

        int k = 1;
        string answer = res;
        int ansLength = answer.length();
        string finAns = answer;
        while (k < answer.length())
        {
            string str = answer.substr(k);

            if (checks(str, p))
            {
                if (str.length() < ansLength)
                {
                    finAns = str;
                    ansLength = str.length();
                }
            }
            else
            {
                finalArr.push_back(finAns);
                break;

            }

            k++;
        }
        // finalArr.push_back(finAns);
        continue; // no smallest window
        }
        int finLength = INT_MAX;
        string result ;
        for (int i = 0; i < finalArr.size(); i++)
        {
            cout << finalArr[i] << " ";
        }
        cout << endl;
        cout<<finalArr.size()<<endl;
        for (int i = 0; i < finalArr.size(); i++)
        {
            if (finalArr[i].length() < finLength)
            {
                result = finalArr[i];
                finLength = finalArr[i].length();
            }
        }
        return result;
    }
    



int main()
{
    string s = "timetopractice";
    string p = "toc";
    string t = "actice";
    
    cout<<smallestwind(s,p)<<endl;
}