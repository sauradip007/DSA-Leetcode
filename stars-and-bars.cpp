#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s = "|**|*|*";
    vector<int>startIndex{1,1};
    // vector of start index
    vector<int> endIndex{5,6};
    vector<int>ans;
    //vector of end index
    
    // while(i < s.length())
    // {

    // }

    for(int i = 0 ; i < startIndex.size(); i++)
    {
        if(startIndex[i] >= endIndex[i])
        continue;
        string res = "";
        int st = startIndex[i]-1;
        int en = endIndex[i]-1;
        //2 substrings obtained
        for(int j = st; j <= en; j++)
        {
            res += s[j];

        }

    // cout<<res<<endl;



        int s_bar = 0,e_bar = 0;
        if(res.find("|") >= 0 && res.find("|") <= res.length()-1)
        {
            //first bar obtained
             s_bar = res.find("|");
        }
        int l = s_bar;
        while(l <= en)
        {
            
            if(res[l] == '|')
            {
                e_bar = l;
            }
            l++;
        }
   
        int  k = s_bar;
        int count_star = 0;
        while(k <= e_bar)
        {
            if(res[k] == '*')
            {
                count_star++;
            }
            k++;
        }
        ans.push_back(count_star);

    }
  for(int i = 0 ; i < ans.size(); i++)
  {
    cout<<ans[i]<<" ";
  }cout<<endl;

}