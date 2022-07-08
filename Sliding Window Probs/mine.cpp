#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i = 0 , j = 0;
    int sum = 0;
    int k = 3;
    vector<int>a{1,2,3,4,5};
    int mx = INT_MIN;
    while(j < a.size())
    {
        sum+=a[j];
        if(j-i+1 < k)
        {
            j++;
            continue;
        }
        else if(j-i+1 == k)
        {
            mx = max(sum,mx);
            sum-=a[i];
            i++;
            j++;
            continue;
        }
    }
    cout<<"Max is : "<<mx<<endl;
}