#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string simplifyPath(string path)
{
    stack<string>st;
    string t = "";
    string res = "";
    for(int i = 0 ; i < path.size(); i++)
    {
        string t = "";
        if(path[i] == '/')
        {
            
            continue;
        }
        while(i < path.size() && path[i] != '/')
        {
          t+= path[i];
            i++;
        }
        if(t == ".")
        {
            continue;
        }
        if(t == "..")
        {
            if(!st.empty())
            {
                st.pop();
            }
            continue;
        }
        st.push(t);
    }
    if(st.empty())
    {
        res += "/"; 
    }
    // res += "/";
    while(!st.empty())
    {
        res = "/" + st.top() + res;
        st.pop();
    }
    return res;
    // stack<char> s;
    // string t="";
    // for(int i = 0 ; i < path.length()-1; i++)
    // {
    //     if(path[i] == '/' && path[i+1] == '/')
    //     {
    //         continue;
    //     }
    //     if(i == 0 && path[i] == '/')
    //     {
    //         continue;
    //     }
    //     if(i == path.length() - 1 && path[i] == '/')
    //     {
    //         continue;
    //     }
    //     s.push(path[i]);
        
        
    // }
    // while(!s.empty())
    // {
     
    //     t += s.top();
    //     s.pop();
      
    // }
    // reverse(t.begin(),t.end());
    // return t;
    
}
string simply(string path)
{
    stack<string> st;
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '/')
            continue;
        string s;
        while (i < path.size() && path[i] != '/')
        {
            s += path[i];
            i++;
        }
        if (s == ".")
            continue;
        else if (s == "..")
        {
            if (!st.empty())
                st.pop();
        }
        else
            st.push(s);
    }
    string res;
   
    while (!st.empty())
    {
        res = "/" + st.top() + res;
        st.pop();
    }
   cout<<res<<endl;
    if (res.size() == 0)
        return "/";
    return res;
}
int main()
{
    string h = "/home/foo//..";
    cout<<simply(h)<<endl;
}