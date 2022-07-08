#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<unordered_map>
using namespace std;
int main()
{
    vector<int>a{4,3,2,7,8,2,3,1};
    vector<int> freq;
    unordered_map<int,bool>seen;
    int count = 0;

    for(int i = 0 ; i < a.size(); i++)
    {
        if(seen.count(a[i]) >  0)
        {
            freq.push_back(a[i]);
            continue;
        }
        else{
        seen[a[i]] = true;
       
        }
    }
    // for(int i = 0 ; i < a.size(); i++)
    // {
    //     count = 0;
    //     for(int j = 0; j < a.size() ; j++)
    //     {
    //         if(i == j)
    //         {
    //             continue;
    //         }
    //         if(a[j] == a[i])
    //         {
    //             count++;
                
    //         }
            
            
    //     }
    //     freq.push_back(count + 1);
    // }

    for(int i = 0 ; i < freq.size(); i++)
    {
        cout<<freq[i]<<" ";
    }cout<<endl;
}