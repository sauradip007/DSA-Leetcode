#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    vector<int>a{100,200,300,400};
    int n = a.size();
    int k = 2;
    int sum = 0;
    int ans = INT_MIN;
    int i = 0;
    int j = 0;
    while(j < n)
    {
        sum += a[j];
        if(j-i+1 < k)
        {
            j++;
            continue;
        }
        else if(j-i+1 == k)
        {
            ans = max(ans,sum);
            sum = sum - a[i];
            i++;
            j++;
            continue;
        }
    }
    cout<<"The max sum is : "<<ans<<endl;
}