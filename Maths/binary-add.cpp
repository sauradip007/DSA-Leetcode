#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
int toInt(int n)
{
    if(n == 0)
    return 0;
    // To convert a no back to binary
    vector<int>binary;
    int base = 2;
    while(n != 0)
    {
        int dig = n % 2;
        binary.push_back(dig);
        n = n/2;
    }
  reverse(binary.begin(),binary.end());
    // for(int i = 0; i < binary.size(); i++)
    // {
    //     cout<<binary[i]<<" ";
    // }cout<<endl;
    int base_10 = 1;
    int sum_10 = 0;
    int j = binary.size()-1;
    while(j >= 0)
    {
        int dig_10 = binary[j]*base_10;
        base_10 *= 10;
        sum_10 += dig_10;
        j--;
    }
    return sum_10;
}
int toBin(string s)
{
    int j = s.length()-1;
    int base = 1;
    int sum = 0;
    while(j >= 0)
    {
        int dig = ((int)s[j]-'0') * base;
        base *= 10;
        sum += dig;
        j--;
        
    }
    // return sum;

    // converted to no
    // To convert to binary

    int base_2 = 1;
    int sum_2 = 0;
    while(sum != 0)
    {
        int dig_2 = (sum%10)*base_2;
        base_2 *= 2;
        sum_2 += dig_2;
        sum = sum/10;
    }
    return sum_2;    

}

string ansToNum(int ans)
{
    string res = "";
    if(ans == 0)
    {
        return "0";
    }
    int base = 1;
    int sum = 0;
    while(ans != 0)
    {
        int ascii = ans%10 + 48;
        int dig = (char)ascii;
        // base *= 10;
        res += dig;
        ans = ans/10;
    }
reverse(res.begin(),res.end());
return res;



}
int main()
{
    // string s = "11";
    // string t = "1";
    // int n1 = toBin(s);
    // int n2 = toBin(t);
    // // int sum = n1 + n2;
    // // cout<<toInt(sum)<<endl;
    // cout<<toBin(s)<<endl; //3
    // cout<<toBin(t)<<endl;
    // int sum = n1+n2; //4
    // cout<<toInt(sum)<<endl;
    // string num = ansToNum(100);
    // cout<<num<<endl;

    string s = "0";
    string t = "0";
    int n1 = toBin(s);
    int n2 = toBin(t);
    int sum = n1+n2;
    int ans = toInt(sum);
    cout<<n1<<" "<<n2<<" "<<"sum : "<<ansToNum(ans)<<endl;

    cout<<"+" - "0"<<"9"-"0"<<endl;
}