#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool comp(int a, int b)
{
    return (a < b);
}
int main()
{
   
    // Brute force
    // vector<int>b; 
    // while( i < n )
    // {
    //     if(a[i] == 0)
    //     {
    //         countZero++;
    //     }
    //     i++;
    // }
    // i = 0;
    // while(i < n)
    // {
    //     if(a[i] != 0)
    //     {
    //         b.push_back(a[i]);
    //     }
    //     i++;
    // }
    // int k = 0;
    // while ( k <= countZero )
    // {
    //     b.push_back(0);
    //     k++;
    // }
    // a.clear();

    // for(int i = 0 ; i < b.size() ; i++)
    // {
    //     a.push_back(b[i]);
    // }
    // for(int i = 0 ; i < a.size(); i++)
    // {
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    // Optimised
    vector<int> a{0, 1, 0, 3, 12};
    int n = a.size();
    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(a[i] != 0)
        {
            swap(a[i],a[j]);
            i++;
            j++;
        }
        else{
            i++;
        }

    }
    for(int i = 0 ; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    }