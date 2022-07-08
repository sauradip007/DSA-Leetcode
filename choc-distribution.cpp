#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int maxel(vector<int> a)
{
    int maxel = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        maxel = max(maxel, a[i]);
    }
    return maxel;
}
int minel(vector<int> a)
{
    int minel = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        minel = min(minel, a[i]);
    }
    return minel;
}
int main()
{
    int m = 5;
    vector<int> a{3, 4, 1, 9, 56, 7, 9, 12};
    sort(a.begin(), a.end());
    int diff = INT_MAX;
    for (int i = 0; i < a.size() - (m - 1); i++)
    {

        // a[i]; //min val
        // a[m-1]; //max val of subarr

        int mdiff = a[m + i - 1] - a[i];
        diff = min(mdiff, diff);
    }
    cout << "Min diff : " << diff << endl;
}