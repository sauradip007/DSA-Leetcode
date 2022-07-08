#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include<math.h>
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
string smallestWindow(string s, string p)
{
    string res = "";
    unordered_map<char,int>str;
    unordered_map<char,int>pat;
    for(int i = 0 ; i < p.length() ; i++)
    {
        pat[p[i]]++;
    }
    for(int i = 0; i < s.length(); i++)
    {
        str[s[i]]++;
    }
    int count = pat.size();
    int start; //start of substring
    int end; //end of substring
    int countStart = 0;
    for(int i = 0 ; i < s.length();i++)
    {
        // int i = 0;
        string res = "";
        while(pat.find(s[i]) != pat.end() && i < s.length())
        {
            res += s[i];
            count--;
            pat[s[i]]--;
            if(countStart = 0)
            {
            start = i;
            countStart++;
            }
            end = i;
            
            if(pat.find(s[i])->second == -1)
            {
                
                count++;
            }
            // if all distinct chars are 0
            if (count == 0)
            {
                int ans = INT_MAX;
                ans = min(ans,end-start+1);
                // start++;
                // end++;
                res = "";
                continue;

            }
            i++;
        }
       
    }
    // string res = "";
    // int n = s.length();
    // int m = p.length();
    // unordered_map<char,int>M;
    // for(int i = 0 ; i < p.length(); i++)
    // {
    //     M[p[i]]++; //counts unique chars in p

    // }

    // int i = 0;
    // int j = 0;
    // while(j < 0)
    // {
    //     if(M.find(s[j]) != M.end())
    //     {
    //         //if the first element of s is present in p
    //     }
    // }
}
string smallestwind(string s , string p)
{
    if(p.length() == 0)
    {
        return "";
    }
    unordered_map<char,int>pat;
    // first we traverse p and populate the map with its frequency
    for(int i = 0 ; i < p.length() ;i++)
    {
        pat[p[i]]++;
    }
    string res = ""; //smallest window substring
    // Now we find the minimum string where all chars of p are present in s
    int count = pat.size(); //no of distinct chars in p
    for(int i = 0; i < s.length() ; i++)
    {
        res += s[i];
        if(pat.find(s[i]) != pat.end())
        {
            
            pat[s[i]]--;
            count--;
            if(pat[s[i]] < 0)
            {
                count++;
                //encorporated dups
            }

        }
        if(count == 0)//all chars are found up untill now
        {
            break;
            // Make all char freqs 0 for reference later
            // unordered_map<char,int>::iterator it = pat.begin();
            // while(it != pat.end())
            // {
            //     it->second = 0;
            //     it++;
            // }

        }
        
    }

    //Now we start deleting all the chars from the beginning of the string res one by one untill the minimum result is obtained
   
    // int ansLength = INT_MAX;
    // string finAns = res;
    // for (int i = 0; i < p.length(); i++)
    // {
    //     pat[p[i]]=0;
    // }
    // for(int i = 0; i < p.length(); i++)
    // {
    //     pat[p[i]]++;
    // }
    // for(int i = 0 ; i < res.length(); i++)
    // {
    //     string ans = res.substr(i);
        
    //     int count = 0;
    //     for(int k = 0 ; k < ans.length(); k++)
    //     {
    //         unordered_map<char,int>freq;
    //         freq[ans[k]]++;
    //         if(pat.find(ans[k]) != pat.end() && freq[ans[k]] != 0)
    //         {
    //             freq[ans[k]] = 0;
    //             count++;
    //         }
    //        if (i == ans.length()-2)
    //       {
    //           cout << freq.size() << endl;
    //           unordered_map<char, int>::iterator it = freq.begin();
    //           while (it != freq.end())
    //           {
    //               it->second = 0;
    //               it++;
    //             }    
    //       }
            
    //         continue;
    //     }
        
    //     if(count >= pat.size())
    //     {
    //         int leng = ans.length();
    //             if (leng < ansLength)
    //             {
    //                 ansLength = leng;
    //                 finAns = ans;
    //             }
               
    //     }
    //     else{
    //         break;
    //     }
    
    // }
   
    // return finAns; //no smallest window

    
   
  
    int i = 1;
    string answer = res;
    int ansLength = answer.length();
    string finAns = answer;
    while(i < answer.length())
    {
        string str = answer.substr(i);

        if(checks(str,p))
        {
            if(str.length() <= ansLength)
            {
                finAns = str;
                ansLength = str.length();

            }
          
        }
        else{
            return finAns;
        }
       
        i++;

    }
  

    return finAns; // no smallest window
}

int main()
{
    string s = "timetopractice";
    string p = "toc";
    cout<<smallestwind(s,p)<<endl;
    string a = "toprac";
    cout<<checks(a,p)<<endl;
    cout<<a.substr(0)<<endl;
}