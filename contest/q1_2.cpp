#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string greatestLetter(string s)
{
    string ans = "";
    char a = ' ';
    int i = 0;
    char req = ' ';
    while(i < s.length())
    {
        if((int)s[i] >= 97 && (int)s[i] <= 122)
        {
            req = char((int)s[i] - 32);
        }
        if ((int)s[i] >= 65 && (int)s[i] <= 90)
        {
            // Uppercase
             req = char((int)s[i] + 32);
        }
        if(s.find(req) >= 0 && s.find(req) <= s.length()-1)
        {
            //found
            int found = s.find(req);
            if(toupper(req) > toupper(a))
            {
                a = req;
            }
            else{
                i++;
                continue;
            }
        }
        i++;
    }
    
    if(a == ' ')
    {
    
    return "";
    }
    else
    {
        a = (char)toupper(a);
        ans += a;
    }
    return ans;
    
 }
int main()
{
    // string s  = "lEeTcOdE";
    // char req = char((int)s[1] + 32);
    // cout<<(char)toupper(req)<<endl;
    // cout<<toupper(' ')<<endl;
    // cout<<req<<endl;
    // cout<<s.find(req)<<endl;

    // cout<<s+req<<endl;
    string s = "AabvdweEfF";
    cout<<greatestLetter(s)<<endl;
}