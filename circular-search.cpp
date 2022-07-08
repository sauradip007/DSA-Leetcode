#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main()
{
    vector<string>a{"saw", "hammer", "mallet","file", "saw", "ladder", "scissor"};
    
    string target = "saw";
    int startIndex = 6;
    int i = startIndex;
    int count = 0;
    int res = INT_MAX;
    while (count <= 7 )
    {
        string str = "";
        str = a[i];
        if(str != target)
        {
            if(i != startIndex)
            count++;
            
            
        }
        else
        {
            if (i != startIndex)
            {
            count++;
            }
            res = min(count,res);
            cout<<count<<endl;
            break;
        }
       
        i = (i+1)%a.size();
        continue;
    }
    cout<<count<<endl;
}