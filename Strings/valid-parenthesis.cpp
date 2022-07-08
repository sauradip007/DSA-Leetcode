
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include<stack>
using namespace std;
bool check(char a, char b)
{
    if(a == '(' && b ==')' || a == '{' && b=='}' || a =='[' && b==']')
    return true;
    else
    return false;
    
}
bool validParenthesis(string s)

{
    stack<char>a;
    int i = 0;
    while(i < s.length())
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            a.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(a.empty())
            {
                return false;
            }
            char popped_ch = a.top();
            a.pop();
            if (!check(popped_ch,s[i] ))
            {
                return false;
            }
        }
        i++;

       
    }
    if (a.empty())
        return true;
    else
        return false;
}
int main()
{

    string s = "{";
    cout<<validParenthesis(s)<<endl;
    
}