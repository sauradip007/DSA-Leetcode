#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a{4,-1,3,5,9};
    int k = 3;
    int i = 0;
    int j = 0;
    int prod = 1;
    int n = a.size();
    int mx = INT_MAX;
    while(j < n)
    {
        prod *= a[j];
        if(j-i+1 < k)
        {
            j++;
            continue;
        }
        else if(j-i+1 == k)
        {
            mx = min(mx,prod);
            prod = prod/a[i];
            i++;
            j++;
            
            continue;
        }
    }
    cout<<"The min triplet prod is : "<<mx<<endl;
}