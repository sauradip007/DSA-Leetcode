#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
bool isPal(string s)
{
    string t = s;
    reverse(s.begin(),s.end());
    if(s == t)
    return true;
    else
    return false;
  }
bool validPalindrome(string s)
{
    // Brute force
    for(int i = 0; i < s.length(); i++)
    {
        string st = "";
        for(int j = 0 ; j < s.length(); j++)
        {
            if(j == i)
            continue;
            st += s[j];


        }
        if(isPal(st))
        return true;
    }
    return false;

}
bool validPalindrome(string s)
{
    // Brute force
    int i = 0;
    int j = s.size() -1;
    while(i < j && j-i <= 1)
    {

    }
}
int main()
{
    cout<<validPalindrome("aba")<<endl;
}