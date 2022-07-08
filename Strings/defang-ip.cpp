#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string defangIPaddr(string address)
{
    // Using insert
    for(int i = 0 ; i <= address.length(); i++)
    {
        if(address[i] == '.')
        {
            address.insert(i,1,'[');
            address.insert(i+2,1,']');
            i+=2;
        }
    }





    string sol = " ";
    string m = "[.]";

    for(int i = 0 ; i < address.length(); i++)
    {
        if(address[i] == '.')
        {
            sol += m;
        }
        else
        {
            sol += address[i];
        }
    }
    return sol;
// string a;

// int i = 0;
// while(address[i] != '\0')
// {
//     if(address[i] == '.')
//     {
      
//       a.push_back('[');
//       a.push_back('.');
//       a.push_back(']');
//       i++;
//         continue;

//     }
//     a.push_back(address[i]);
//     i++;




// }


// return a;





}
int main()
{
    string b = "1.1.1.1";
    string c = defangIPaddr(b);
    cout<<c<<endl;
}