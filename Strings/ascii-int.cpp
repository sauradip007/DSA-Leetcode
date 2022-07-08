
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main()
{
    string s = "3+2*9";
    cout<<(int)s[0] - '0' <<endl;
    cout<<(int)s[4]<<endl;
    cout<<"ASCII IS : " <<s[1] - '0'<<endl;
    string t = "11";
    cout<<(int)t[0]<<endl;

    

    cout<<"The remainder is : "<<0%10<<endl;
    int dig = (0%10) + 48;
    char a = (char)dig;
    cout << a << endl;
}
