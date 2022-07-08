#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
// int pairsum(vector<int>a)
// {
//     sort(a.begin(), a.end());
//     int i = 0;
//     int k = 6;
//     int j = a.size() - 1;
//     while (i < j)
//     {
//         if (a[i] + a[j] < k)
//         {
//             i++;
//         }
//         else if (a[i] + a[j] > k)
//         {
//             j--;
//         }
//         else
//         {
//             cout << a[i] << " " << a[j];
//             i++;
//             j--;
//         }
//         cout << endl;
//     }
// }
int bsearch(vector<int>a, int x)
{
    int start = 0;
    int end = a.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (x > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a{1, 0, 1, 2, -1, -4};
    unordered_map<int,int>freq;
    int k = 0;
    vector<int> triplet;
    vector<vector<int>>ans;
    sort(a.begin(),a.end());
    int i = 0;
    int j = i+1;

    for(int i = 0 ; i < a.size() ; i++)
    {
        freq[a[i]] = 0;
    }
    while(i < a.size() && j < a.size())
    {
      
        int pairsum = a[i] + a[j];
        int s = bsearch(a, k - pairsum);
        freq[a[i]]++;
        // freq[a[i]] = true;
        if (s != i && s != j && s != -1 && freq[a[i]] <= 1)
        {
            triplet.push_back(a[i]);
            triplet.push_back(a[s]);
            triplet.push_back(a[j]);
            // freq[a[i]] = false;
            freq[a[s]]++;
            i++;
           j++;
        }
        else{
            i++;
            j++;
            continue;
        }
        ans.push_back(triplet);
        triplet.clear();

    }
    for(int i = 0 ; i < ans.size(); i++)
    {
        for(int j = 0 ; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout << endl;
    }

}