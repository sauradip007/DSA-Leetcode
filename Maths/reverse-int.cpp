
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int reverseinteger(int x)
{
if (x >= INT_MAX || x <= INT_MIN)
{
    return 0;
}
int neg = 0;
if( x < 0 )
{
    neg = x;
    x = x*(-1);
}
int units = x % 10;
int i = 0;
int res;
int count = 0;
vector<int> digs;
while (x != 0)
{
    res = x % 10;
    // int dig = res % 10;
    digs.push_back(res);
    count++;
    x = x / 10;
}
int sum = 0;
int base = pow(10,count-1);
for(int i  = 0; i < digs.size(); i++)
{
    sum += digs[i]*base;
    base /= 10;
}
if(neg < 0)
{
    return sum * (-1);
}
else
return sum;

}
int main()
{
    cout<<reverseinteger(-2148712)<<endl;
    cout<<INT_MAX<<" "<<INT_MIN<<endl;
}
