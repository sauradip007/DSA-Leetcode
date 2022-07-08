#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int arr[n];
    int k;
    cin >> k;//sum
    int mx = INT_MIN;
    int i = 0;
    int j = 0; // i denotes start and j end of the window
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while(j < n)
    {
        sum = sum + arr[j];
        if(sum < k)
        {
            j++;
            continue;
        }
        else if(sum == k)
        {
            mx = max(j-i+1,mx);
            j++;
        }
        else{
            while(sum > k && i < n)
            {
                sum = sum - arr[i];
                i++;
                //we have already reached and calcukated max window size for j so we increment j as well
            }
            j++;
        }
    }
    cout<<"Max window size : "<<mx<<endl;
}