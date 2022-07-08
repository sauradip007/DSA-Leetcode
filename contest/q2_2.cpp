#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int minimumNumbers(int num, int k)
{
    // int i = k;
    // int n = num;
    
    // vector<int>ans;
    if(k > num || num == 0)
    {
        return 0;
    }
    if(num == k)
    {
        //only 1 possibility
        return 1;
    }
    int count = 0;
    vector<int>res;
    for(int i = k ; i < num; i++)
    {
        if(i % 10 != k)
        {
        continue;
        }
        res.push_back(i);

        for(int j = i ; j < num ; j++)
        {
            if(j != num - i || j == i)
            {
                continue;
            }
            if(j % 10 == k)
            {
                res.push_back(j);
                break;
                
            }
        }
        if(res.size() == 2)
        {
            count++;
            res.clear();
            continue;
        }
        else{
            res.clear();
            continue;
        }
    }
    if(count == 0)
    return -1;
    else
    return count;
    //     for(int i = k ; i < num; i++)
    //     {
    //         if(i % 10 != k)
    //         {
    //             continue;
    //         }
    //     int start = i;
    //     int end = num;
    //     // if(num-i < start)
    //     // {
    //     //     continue;
    //     // }
    //     res.push_back(i);
    //     while(start <= end)
    //     {
    //         int mid = (start+end)/2;
    //         if(mid == (num-i))
    //         {
    //             if(mid % 10 == k)
    //             {
    //             res.push_back(mid);
    //             }
    //             else
    //             break;
    //         }
    //         else if(mid < (num-i))
    //         {
    //             start = mid+1;
    //         }
    //         else
    //         {
    //             end = mid-1;
    //         }
    //     }
    //     if(res.size() == 2)
    //     {
    //         // Pair exists
    //         count++;
    //         res.pop_back();
    //         res.pop_back();
    //     }
    //     else
    //     {
    //         res.pop_back();
    //         continue;
    //     }
    //  }
    
 }

   

int main()
{
    cout<<minimumNumbers(37,2)<<endl;

}