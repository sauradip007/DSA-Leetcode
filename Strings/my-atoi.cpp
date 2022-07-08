#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
// int myAtoi(string s)
// {
//     stack<int> st;
//     char op = '+';
//     if (s.find("-") >= 0 && s.find("-") <= s.length() - 1)
//     {
//         op = '-';
//     }
//     int curr = 0;
//     if ((int)s[0] >= 65 && (int)s[0] <= 90 || (int)s[0] >= 97 && (int)s[0] <= 122)
//     {
//         return curr;
//     }
//     for (int i = 0; i < s.length(); i++)
//     {

//         if (s[i] == ' ')
//             continue;

//         if (s[i] >= '0' && s[i] <= '9')
//         {
//             while (s[i] >= '0' && s[i] <= '9')
//             {
//                 curr = curr * 10 + (s[i] - '0');
//                 i++;
//             }
//             //                 if(op == '+')
//             //             {
//             //                 st.push(curr);
//             //                 //+ve val
//             //             }
//             //             else if (op == '-'){
//             //                 st.push(-curr);

//             //             }
//         }
//         else
//             continue;
//     }
//     // push back contents into stack
//     int res = 0;
//     // while(!st.empty())
//     // {
//     //     res += st.top();
//     //     st.pop();
//     // }
//     if (op == '+')
//         return curr;
//     else
//         return (-1) * curr;
// }

int newatoi(string s)
{
    char op = '+';
    if (s.find("-") >= 0 && s.find("-") <= s.length() - 1)
    {
        op = '-';
    }
    long long int curr = 0;
    if ((int)s[0] >= 65 && (int)s[0] <= 90 || (int)s[0] >= 97 && (int)s[0] <= 122)
    {
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == ' ')
            continue;

        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                curr = curr * 10 + (s[i] - '0');
                i++;
            }
        }
        else
            continue;
    }
    // push back contents into stack

    // final ans with sign after coming out of for loop
    long long int res = 0;
    if(op == '+')
    {
        res = curr;
    }
    if(op == '-')
    {
        res = -curr;
    }
    // we finally check the sign
    if(res >= INT_MAX)
    {
        return INT_MAX;
    }
    else if (res <= INT_MIN)
    {
        return INT_MIN;
    }
    else
    return res;
   

    if (op == '+')
    {
        if (curr >= INT_MAX)
        {
            return INT_MAX;
        }
        else if (curr <= INT_MIN)
        {
            return INT_MIN;
        }
        else
        return (int)curr;
    }
    else
    {
        if (curr >= INT_MAX)
        {
            return INT_MAX;
        }
        else if (curr <= INT_MIN)
        {
            return INT_MIN;
        }
        else{
            int res = (-1)*curr;
            return res;
        }
    }
    return 0;
}
int main()
{
    char op = '+';
    string s = "- 91283472332"; 
    if (s.find("-") >= 0 && s.find("-") <= s.length() - 1)
        {
            op = '-';
        }

        cout<<op<<endl;
}
