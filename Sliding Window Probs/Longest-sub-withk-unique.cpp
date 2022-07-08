#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include<map>
using namespace std;




    // int i = 0;
    // int j = 0;
    // int n = s.length();
    // map<char, int> m;
    // int mx = -1;
    // while (j < n)
    // {
    //     if (m.size() < k)
    //     {
    //         m[s[j]]++;
    //         j++;
    //     }

    //     else if (m.size() == k)
    //     {
    //         mx = max(mx, j - i + 1);
    //         j++;
    //     }

    //     else if (m.size() > k)
    //     {
    //         while (m.size() > k)
    //         {
    //             m[s[i]]--;
    //             if (m[s[i]] == 0)
    //             {
    //                 m.erase(s[i]);
    //             }
    //             i++;
    //         }
    //         j++;
    //     }
    // }
    // return mx;

int main()
{
    string a = "aabacbebebe";
    int i = 0;
    map<char,int> M;
    int j = 0;
    int k = 3;
    int mx = -1;
   
    int n = a.length();
    while(j < n)
    {

        M[a[j]]++;
        if(M.size() < k)
        {
            
            j++;
        }
        else if(M.size() == k)
        {
          
            mx = max(j-i+1,mx);
            // res = "";
           
            j++;

        }
        else{
            while(M.size() > k && i < n)
            {
                // Remove map entry for that key
                M[a[i]]--;
                if(M[a[i]] == 0)
                {
                    M.erase(a[i]);
                }
                i++;
            }
            j++;

        }
    }
    cout<<"The max unique substring leng is : "<<mx<<endl;
}