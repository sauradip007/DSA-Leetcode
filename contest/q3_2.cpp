#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include<math.h>
using namespace std;
int longestSubsequence(string s, int k)
{
}
int main()
{
    // string t = "1001010";
    // int z = 0;
    // int i = 0;
    // while(i < t.length())
    // {
    //     if(t[i] == '0')
    //     {
    //         z++;//counts the no of zeroes
    //     }
    //     i++;
    // }
    // int k = 5;
    // int n = stoi(t);
    // int sum = 0;
    // int countDigs = 0;
    // int dig = 1;
    // int countSum = 0;
    // int base = 1;
    // while (n != 0)
    // {

    //     if (n % 10 == 0)
    //     {
    //         z--;
    //         countSum++;
    //         base *= 2;
    //         n = n / 10;
    //         continue;
    //     }
    //     sum += base;

    //     countSum++;
    //     if (sum > k)
    //     {
    //         sum = sum - base;
    //         countSum--;
    //     }
    //     base *= 2;
    //     n = n / 10;
    // }
    // cout << z + countSum << endl;
    string t = "00101001";
    int z = 0;
    int i = 0;
    while(i < t.length())
    {
        if(t[i] == '0')
        {
            z++;//counts the no of zeroes
        }
        i++;
    }
    int k = 1;
    int n = stoi(t);
    int sum = 0;
    int countDigs = 0;
    int dig = 1;
    int countSum = 0;
    int base = 1;
    for(int i = t.length()-1; i >= 0; i--)
    {
      if(t[i] == '0')
      {
        z--;
        countSum++;
        base*=2;
        continue;

      }
      if(sum+base > k)
      {
        continue;
      }
      sum += base;
      countSum++;
      base *= 2;
      continue;
      //   if(sum > k)
      //   {
      //     sum = sum-base;
      //     countSum--;
      //   }
     
    }
    cout<<z+countSum<<endl;
}