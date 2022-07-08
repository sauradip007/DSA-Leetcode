
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int main ()
{
    string s = "God Ding";
    string t = "happily";
    reverse(t.begin(),t.begin()+2);
    cout<<t;
}