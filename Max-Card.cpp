#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int myscore(vector<int>&cardPoints,int k)
{
    vector<int>sumUp;
    int sum = 0;
    for(int i = 0; i < cardPoints.size(); i++)
    {
        sum += cardPoints[i];
        sumUp.push_back(sum);
    }
    if(k == cardPoints.size())
    {
        return sum;
    }
    for(int i = 0 ; i < sumUp.size(); i++)
    {
        cout<<sumUp[i]<<" ";
    }cout<<endl;
    cout<<sum<<endl;
    cout<<sumUp[4]-sumUp[0]<<endl;
    int i = 0;
    int j = 0;
    int n = cardPoints.size();
    int ans = INT_MIN;
    int reqSum = 0;
    while(j < n)
    {
        if(j-i+1 < n-k)
        {
            j++;
            continue;
        }
        else
        {
            
            //compute ans
           
            // handle the i = 0 corner case
            if(i == 0)
            {
                reqSum = sumUp[j];
            }
            else{
            reqSum = sumUp[j] - sumUp[i - 1];
            }

            ans = max(sum - reqSum, ans);

            i++;
            j++;
            continue;
        }
      
    }
    return ans;

}
int maxScore(vector<int> &cardPoints, int k)
{
        vector<int>sum;
        int sumUp = 0;

        for(int i = 0 ; i < cardPoints.size(); i++)
        {
            sumUp += cardPoints[i];
            sum.push_back(sumUp);
        }
        if(k == cardPoints.size())
        {
            return sumUp;
        }
        // Start the sliding window
        int score = 0;
        int ans = 0;
        for(int i = 0; i <= k; i++)
        {
            //To calculate upto starting
            int j = i + cardPoints.size()-k-1;//so that size f window remains 4 (the part we are not considering subarray so in first case i will go from 0->3)
            if(i == 0)
            {
            ans = sum[j];
            }//since i-1 will be out of bound
            ans =  sum[j] - sum[i-1];   //sum of the subarray we are not considering using prefix sum concept
            score = max(score,sumUp-ans);

        }
        return score;
}
// int maxScore(vector<int> &cardPoints, int k)
// {
//     // if(k > cardPoints.size())
//     // {
//     //     return 0; //not possible
//     // }
//     // if (k == cardPoints.size())
//     // {
//     //     int sum = 0;
//     //     for (int i = 0; i < cardPoints.size(); i++)
//     //     {
//     //         sum += cardPoints[i];
//     //     }
//     //     return sum;
//     // }

//     // int i = 0; 
//     // int j = cardPoints.size()-1;
//     // int maxSum = 0;
//     // int count = 0;
//     // while(i < j)
//     // {
//     //     if(count == k)
//     //     {
//     //         break;
//     //     }
//     //     if(cardPoints[i] > cardPoints[j])
//     //     {
//     //         maxSum += cardPoints[i];
//     //         i++;
//     //         count++;
//     //         continue;
//     //     }
//     //     else if(cardPoints[i] < cardPoints[j])
//     //     {
//     //         maxSum += cardPoints[j];
//     //         j--;
//     //         count++;
//     //         continue;
//     //     }
//     //     else //if they are equal we consider both cases
//     //     {
//     //         //Case 1: front side
//     //         if(i < j)
//     //         {
//     //             int k = i;
//     //             int l = j;
//     //             while(cardPoints[k] == cardPoints[l] && k < l)
//     //             {
//     //                 k++;
//     //                 l--;

//     //             }
//     //             if(cardPoints[k] > cardPoints[l])
//     //             {
//     //                 maxSum += cardPoints[i];
//     //                 i++;
//     //                 count++;
//     //                 continue;

//     //             }
//     //             else 
//     //             {
//     //                 maxSum += cardPoints[j];
//     //                 j--;
//     //                 count++;
//     //                 continue;
//     //             }
              
//     //         }
//     //         else
//     //         {
//     //         maxSum += cardPoints[i];
//     //         break;
//     //         }
            
            
//     //     }

//     // }
//     // return maxSum;

// }
int maximumScore(vector<int>&cardPoints,int k)
{
    vector<int> sum;
    int sumUp = 0;

    for (int i = 0; i < cardPoints.size(); i++)
    {
        sumUp += cardPoints[i];
        sum.push_back(sumUp);
    }
    if(k == cardPoints.size())
    {
        return sumUp;
    }
    // cout<<sumUp<<endl;
    int i = 0;
    int j = 0;
    int ans = 0;
    int score = INT_MIN;
    while(j < cardPoints.size())
    {
        if(j-i+1 < cardPoints.size()-k)
        {
            j++;
            continue;
        }
        else if(j-i+1 == cardPoints.size()-k)
        {
            if(i == 0)
            {
                ans = sum[j];//out of bound
            }
            else{
                ans = sum[j] - sum[i-1];

            }
            score = max(score,sumUp-ans);
            i++;
            j++;
            // continue;
        }

    }
    return score;
}
int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 1};
    cout<<myscore(a,3)<<endl;
}