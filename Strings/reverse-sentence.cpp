#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string reverseWord(string s)
{
    if(s.length() == 0)
    return s;
    
    stack<string>st;
    string rev = "";
    for(int i = 0 ; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        string t = "";
      while(i < s.length() && s[i] != ' ')
      {
          t += s[i];
          i++;
      }
        
        st.push(t);
    }
    if(st.empty())
    return rev;
    while(!st.empty())
    {
        rev += st.top();
        
        st.pop();
        if(!s.empty())
        rev += " ";
    }
    return rev;
}
int main()
{
    string t = "  hello world";
    cout<<reverseWord(t)<<endl;
}