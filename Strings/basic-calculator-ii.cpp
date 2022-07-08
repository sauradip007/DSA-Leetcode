#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
int calculate(string s)
{
    vector<char>sign;
    stack<char>c;
    int n = s.length();
    int i = 0;
    char op = '+'; //no -ve nos
    for(int i = 0 ; i < n; i++)
    {
        if(s[i] == ' ')
        continue;
        int curr = 0;
        if(s[i] >= '0' && s[i] <= '9')
        {
            
            
            while(s[i] >= '0' && s[i] <= '9' && i < n)
            {
                curr = curr*10 + (s[i] - '0');
                i++;
            }
            
            // i--; //goes back to the prev sign to check if it is positive or not
            //digit is calculated
            if(op == '+')
            {
                c.push(curr);
                // i++;
            }
            else if(op == '-')
            {
                c.push(-curr);
                // i++;
            }
            //handle * and / then res +=  contents of stack for final ans
           
          
        }


            if(op == '/')
            {
                int prevNum = c.top();
                c.pop();
                c.push(prevNum/curr);
            }

            else if(op == '*')
            {
                int prevNum = c.top();
                c.pop();
                c.push(prevNum*curr);
            }
           
                op = s[i];
            
        
    }

    int k = 0;
    int res = 0;
    while(!c.empty())
    {
        res += c.top();
        c.pop();

    }
    return res;
    // while(i < n)
    // {
    //     if((int)s[i] >= 48 && (int)s[i] >= 57)
    //     {
    //         // it is a digit
    //         int dig = (int)s[i] - '0';
    //         c.push(s[i]);
    //         i++;
    //         continue;
    //     }
    //     if(s[i] == '+' || s[i])

    // }

}
int main()
{
    string s = "3/2";
    cout<<calculate(s)<<endl;
}