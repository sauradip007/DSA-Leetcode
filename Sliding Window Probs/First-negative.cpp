#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//   vector<int> A{5, -2, -3, 7, -10, -6, 4, 5, -1};
//     queue<long long> q;
//     vector<long long> ans;
//     long long i = 0, j = 0;
//     int K = 3;
//     int N = A.size();
//     while (j < N)
//     {
//         if (A[j] < 0)
//         {
//             q.push(A[j]);
//         }
//         if (j - i + 1 < K)
//         {
//             j++;
//             continue;
//         }
//         else
//         {
//             if (q.empty())
//             {
//                 ans.push_back(0);
//             }
//             else
//             {
//                 ans.push_back(q.front());
//                 if (q.front() == A[i])
//                     q.pop();
//             }
//             i++;
//             j++;
//         }
//         }
//         for (int i = 0; i < ans.size(); i++)
//             cout<<ans[i]<<" ";
// }   vector<int> A{5, -2, -3, 7, -10, -6, 4, 5, -1};

//     queue<long long> q;
//     vector<long long> ans;
//     long long i = 0, j = 0;
//     int K = 3;
//     int N = A.size();
//     while (j < N)
//     {
//         if (A[j] < 0)
//         {
//             q.push(A[j]);
//         }
//         if (j - i + 1 < K)
//         {
//             j++;
//             continue;
//         }
//         else
//         {
//             if (q.empty())
//             {
//                 ans.push_back(0);
//             }
//             else
//             {
//                 ans.push_back(q.front());
//                 if (q.front() == A[i])
//                     q.pop();
//             }
//             i++;
//             j++;
//         }
//         }
//         for (int i = 0; i < ans.size(); i++)
//             cout<<ans[i]<<" ";
// }

        // Optimised approach
        int main(){
             vector<int>a{12,-1,-7,8,-15,30,16,20};

            int k = 3;
            int i = 0;
            int j = 0;
           queue<int>neg;
           vector<int>ans; //this vector stores the answer i.e. the first -ve no of each subarray
            while(j < a.size())
            {
                if(a[j] < 0)
                {
                    neg.push(a[j]);
                }
                if(j-i+1 < k)
                {
                    j++;
                    continue;
                }
                else
                {
                    //window size hit, the first negative element obtaineed untill NOW is the required ans

                    //calculate answer
                    if(neg.empty())
                    {
                       ans.push_back(0);

                    }
                    else
                    {
                    ans.push_back(neg.front());
                  
                    }
                    //now we slide the window
                    if (a[i] == neg.front())
                    {
                        neg.pop();
                    }
                    i++;
                    j++;
                }

            }
            for(int i = 0 ; i < ans.size(); i++)
            cout<<ans[i]<<" ";
        }

        // vector<int>a{5,-2,-3,7,-10,-6,4,5,-1};

        // int k = 3;
        // int mx = INT_MAX;
        // int i = 0;
        // int j = 0;
        // vector<int>neg;
        // // cout << a[j] << endl;
        // while(j < a.size())
        // {

        //     if(j-i+1 < k)
        //     {
        //         j++;
        //         continue;
        //     }
        //     else if (j-i+1 == k)
        //     {
        //         int l = i;
        //         while(a[l] >= 0 && l < a.size() && l <= j)
        //         {
        //             l++;
        //         }
        //         if(a[l] < 0)
        //         cout<<a[l]<<" ";
        //         i++;
        //         j++;
        //         continue;
        //     }
        // }
    