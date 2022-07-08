#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    // Brute force O(n^2)
    vector<int>a{7,1,5,3,6,4};
    vector<int> diff;
    int maxProfit = INT_MIN;
    for(int i = 0 ; i < a.size(); i++)
    {
        for(int j = i ; j < a.size(); j++)
        {
                if(a[j] > a[i])
                {
                int diff = a[j] - a[i];
                maxProfit = max(maxProfit,diff);
                
                }
                
            
        }
    }
    // cout<<maxProfit<<endl;



    // Optimised O(n)
    // vector<int> a{7, 1, 5, 3, 6, 4};
    // int maxProfit = INT_MIN;
    // int minsoFar = a[0];
    // for(int i = 0; i < a.size(); i++)
    // {
    //     minsoFar = min(minsoFar,a[i]);
    //     int profit = a[i] - minsoFar;
     
    //     if( profit >= 0)
    //     {
    //         maxProfit = max(maxProfit,profit);
    //     }
    // }
    // cout<<maxProfit<<endl;
}