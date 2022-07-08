#include<bits/stdc++.h>
#define ll long long int
#define prime 3 //could be any prime no
using namespace std;
ll createHashValue (string str,int n)
{
    ll result = 0; //time complexity of O(n) where n is stirng length
    for(int i = 0 ; i < n; i++)
    {
        result += (ll)((ll)str[i] * (ll)pow(prime,i));
    }
    return result;
}
ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int pattLength)
{
    //oldIndex belongs to that of the old window , this the rehashing function
    ll newHash = oldHash - str[oldIndex]; //subtracting the ascii value of the first index of previous window
    newHash /= prime; //dividing it with the prime no.
    //all we have to do now is to add the last term of the new window
    newHash += (ll)((ll)str[newIndex]*(ll)pow(prime,pattLength-1));
    //pattlength is the pattern length
    return newHash;

}
bool checkEqual(string str1, string str2,int start1, int end1, int start2, int end2)
{
    //this checks the string character by character, if it is false anywhere it returns false
    if(end1-start1 != end2-start2)
    {
    return false;
    }
    //if the length of both substrings are edifferent there will be no matching

    while(start1 <= end1 && start2 <= end2)
    {
        if(str1[start1] != str2[start2]){
        return false;
        }
        start1++;
        start2++;
    }
    return true;

}
int main()
{
    string str = "abczxabcvabc";
    string pat = "abc";
    ll patHash = createHashValue(pat,pat.length());
    //hashvalue of the pattern
    ll strHash = createHashValue(str,pat.length()); // we are passing pat length here as we only have to check for the substring pattern length which is equal to pattern length
    //hash value of the given string to be matched
    for(int i = 0; i <= str.length()-pat.length(); i++)
    {
        if(patHash == strHash && checkEqual(str,pat,i,i+pat.length()-1,0,pat.length()-1))
        {
            return i;
        }
        if(i < str.length()-pat.length())
        {
            strHash = recalculateHash(str,i,i+pat.length(),strHash,pat.length());

        }
    }
    cout<<"Not found"<<endl;
    return 0;


}
// int main()
// {
//     vector<string> strings = {"aa","ab","aa","b","cc"};
//     sort(strings.begin(),strings.end());
//     int distinct = 0;
//     for(int i = 0 ; i < strings.size(); i++)
//     {
//         if(i == 0 || strings[i] != strings[i-1])
//         {
//             distinct++;
//         }
//     }
//     cout<<distinct<<endl;
// }