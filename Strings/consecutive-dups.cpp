
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void removeConsecutiveDuplicates(char s[])
{
    int i = 0;
    int j = 0;
    while(s[i] != '\0')
    {
        if(s[i] == s[i+1])
        {
            i++;
            continue;
        }
        s[j] = s[i];
        i++;
        j++;
    }
    s[j] = '\0';
    // int i = 0;
    // int j = 0;
    // while (input[i] != '\0')
    // {
    //     if (input[i] == input[i + 1])
    //     {
    //         i++;
    //         continue;
    //     }
    //     input[j] = input[i];
    //     j++;
    //     i++;
    // }
    // input[j] = '\0';
    // Write your code here
    // unordered_map<char, bool> freq;
    // vector<char>s;
    // for(int i = 0; input[i] != '\0'; i++)
    // {
    //     if(freq.count(input[i]) > 0)
    //     {
    //         continue;
    //     }
    //     else{
    //         freq[input[i]] = true;
    //         s.push_back(input[i]);
        
    //     }
    // }
    // for(int j = 0 ; j < s.size(); j++)
    // {
    //     cout<<s.at(j);
    // }cout<<endl;

}
int main()
{
    char a[100];
    cin.getline(a,100);
    removeConsecutiveDuplicates(a);
    cout<<a<<endl;

}