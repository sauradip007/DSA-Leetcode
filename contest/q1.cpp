#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
bool strongPasswordCheckerII(string password)
{
    if (password.length() < 8)
    return false;
    string special = "!@#$%^&*()-+";
    int i = 0;
    int countLower = 0;
    int countUpper = 0;
    int countDigit = 0;
    bool flag = false;
    int j = 0;
    //checking adjacent
    while(j < password.length()-1)
    {
        
        if(password[j] == password[j+1])
        {
            return false;
        }
        j++;
    }
    while(i < password.length())
    {
        
        if ((int)password[i] >= 97 && (int)password[i] <= 122)
        {
            countLower++;
        }
        if ((int)password[i] >= 65 && (int)password[i] <= 90)
        {
            countUpper++;
        }
         if((int)password[i] >= 48 && (int)password[i] <= 57)
        {
            countDigit++;
        }
        if (special.find(password[i]) >= 0 && special.find(password[i]) < special.length())
        {
            flag = true;
        }
        i++;
    }
    if(flag == true && countLower >= 1 && countUpper >=1 && countDigit >= 1)
    return true;
    else
    return false;

}
int main()
{
    cout << strongPasswordCheckerII("(Aa1a1a1") << endl;
}