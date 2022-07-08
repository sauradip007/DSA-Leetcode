#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
bool isPalindrome(int x)
{
    int n = 0;
    if(x < 0)
    {
        n = abs(x);
        vector<int> digits;
        while (n != 0)
        {
            digits.push_back(n % 10);
            n = n / 10;
        }
        if (x < 0)
        {
            
            digits.at(digits.size() - 1) = (-1) * digits.at(digits.size() - 1);
        }
        int i = 0;
        int j = digits.size() - 1;
        for (int i = 0; i < digits.size(); i++)
        {
            cout << digits[i] << " ";
        }
        cout << endl;
        while (i < j)
        {
            if (digits[i] == digits[j])
            {
                i++;
                j--;
                continue;
            }
            else
                return false;
        }
        return true;
    }
    vector<int> digits;
    while (x != 0)
    {
        digits.push_back(x % 10);
        x = x / 10;
    }
    if(x < 0){
    int n = digits.size()-1;
    digits.at(digits.size() - 1) = (-1) * digits.at(digits.size() - 1);
    }

    int i = 0;
    int j = digits.size() - 1;
    for(int i = 0 ; i < digits.size() ; i++)
    {
        cout<<digits[i]<<" ";
    }cout<<endl;
    while (i < j)
    {
        if (digits[i] == digits[j])
        {
            i++;
            j--;
            continue;
        }
        else
            return false;
    }
    return true;
}
int main()
{
    cout<<isPalindrome(-1)<<endl;
}