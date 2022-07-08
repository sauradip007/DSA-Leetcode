#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// int solve (vector<int>&potions,int i,long long success)
// {
//     // Assuming potions is already sorted
//     int l = 0;
//     int h = potions.size() - 1;
//     while (l <= h)
//     {
//         int mid = (l+(h-l))/2;
//         if((long long)potions[mid]*(long long)i >= success)
//         {

//         }

//     }
// }


vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    // Use simple binary search

    vector<int> ans;
    for (int i = 0; i < spells.size(); i++)
    {
        int l = 0;
        int h = potions.size() - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if ((long long)potions[mid] *(long long) spells[i] >= success)
            {

                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        ans.push_back(potions.size() - l);
    }
    return ans;
}
    int main()
    {
        vector<int> pairs;
        vector<int> spells{5,1,3};
        vector<int> potions{1,2,3,4,5};
        long long success = 7;
        pairs = successfulPairs(spells, potions, success);
        for (int i = 0; i < pairs.size(); i++)
        {
            cout << pairs[i] << " ";
        }
        cout << endl;
    }