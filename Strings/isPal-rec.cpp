#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// bool isPal(string s, int i , int j)
// {
//     // Compare first and last element is our responsibility, give the rest of the task to rec
//     if(i == j)
//     {
//         // One element is remianing
//         return true;
//     }

//     if(s[i] == s[j])
//     {
//         return isPal(s,i+1,j-1);

//     }
//     return false;
    
// }
bool isPal(string s, int i, int j)
{
    if(i == j)
    {
        return true;
    }
    while(i < j)
    {
        if(s[i] == s[j])
        {
            i++; 
            j--;
        }
        else
        return false;
    }
    return true;
}
bool isValid(string s)
{
    int i = 0; 
    int j = s.length() -1;
    while(i < j)
    {
        if(s[i] == s[j])
        {
            i++;
            j--;
            continue;
        }
        else
        return isPal(s,i+1,j) || isPal(s,i,j-1);
    }
    // Case where no deletions is required and the entire string is a palindrome in itself
    return true;
}
int main()
{
    string T = "adca";
    cout<<isValid(T)<<endl;
}