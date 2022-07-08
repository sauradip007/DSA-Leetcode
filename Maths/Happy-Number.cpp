#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include<math.h>
#include <map>
using namespace std;
int sumsquares(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int d = n % 10;
        sum += pow(d, 2);
        n = n / 10;
    }
    return sum;
}
bool  happy(int n)
{
int x = n;
// int sum = n;
// while (n != 0)
// {
//     int d = n % 10;
//     sum += pow(d, 2);
//     n = n / 10;
// }
// Replacing x with sum

    // sum = sumsquares(n);
    while(1)
    {
        if(x == 1)
        {
        return true;
        }
        if(x == 89) //sum can max go upto 89
        {
        return false;
        }
    int sum = 0;
    while (x != 0)
    {
        int d = x % 10;
        sum += pow(d, 2);
        x = x / 10;
    }
    x = sum;
    }


}
int main()
{
    cout<<happy(19)<<endl;
}