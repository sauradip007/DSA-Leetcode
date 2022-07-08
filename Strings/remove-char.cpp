#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
void removeAllOccurrencesOfChar(char a[], char c)
{
    int i = 0;
    int j = 0;
    while(a[i] != '\0')
    {
        
      if(a[i] == c)
      {
          i++;
          continue;
      }
        a[j] = a[i];
        i++;
        j++;
        // if(a[i] != c)
        // {
        //     i++;
        //     continue;
        // }
        // a[j] = a[i];
        //     j++;
        //     i++;

    }
    a[j] ='\0';


}
int main()
{
    char a[100];
    cin.getline(a,100);
    removeAllOccurrencesOfChar(a,'y');
    cout<<a<<endl;

}