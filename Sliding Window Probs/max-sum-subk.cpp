#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Fixed sliding window
    int n;
    int sum = 0;
    cin >> n;
    int arr[n];
    int k;
    cin >> k;
    int mx = INT_MIN;
    int i = 0;
    int j = 0; // i denotes start and j end of the window
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
            continue;
        }
        else if (j - i + 1 == k)
        {
            mx = max(mx, sum);
            sum = sum - arr[i];
            i++;
            j++;
            continue;
        }
    }
    cout << "Max subarray sum  is : " << mx << endl;
}