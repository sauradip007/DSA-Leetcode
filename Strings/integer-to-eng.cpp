#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
string helper(int num,vector<string>&outer,vector<string>&tens,vector<string>&units)
{
    vector<pair<string, int>> p{{"One",1}, {"Two",2}, {"Three",3},{"Four",4},{"Five",5},{"Six",6},{"Seven",7}, {"Eight",8}, {"Nine",9},{"Ten",10}, {"Eleven",11}, {"Twelve",12},{"Thirteen",13}, {"Fourteen",14}, {"Fifteen",15}, {"Sixteen",16}, {"Seventeen",17}, {"Eighteen",18}, {"Nineteen",19}, {"Twenty",20},{"Thirty",30},{"Forty",40}, {"Fifty",50},{"Sixty",60}, {"Seventy",70}, {"Eighty",80}, {"Ninety",90}, {"Hundred", 100}, {"Thousand",1000}, {"Ten thousand",10000}, {"Million",1000000}, {"Billion", 100000000} };

    vector<string> outer = { "Billion","Million", "Ten thousand","Thousand","Hundred"};
    vector<string> tens { "Ninety","Eighty","Seventy", "Sixty","Fifty","Forty","Thirty","Twenty","Nineteen","Eighteen","Seventeen","Sixteen","Fifteen","Fourteen","Thirteen","Twelve","Eleven","Ten"};
    // reverse(tens.begin(),tens.end());
    // reverse(outer.begin(),outer.end());
    vector<string>units {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
    reverse(units.begin(),units.end());

        if(num == 0)
        {
            return "";
            // Base case
        }
        if(num >= 1000000000)
        {
           
            return outer[0] + " " + helper(num/1000000000,outer,tens,units);
        }
        if(num >= 1000000)
        {
        return outer[1] + " " + helper(num/1000000,outer,tens,units);
        }

        

}