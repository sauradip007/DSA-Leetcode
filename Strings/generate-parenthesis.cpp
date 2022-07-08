#include<iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// For n = 4 -> ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
vector<string> generateParenthesis(int n)
{
    vector<string> output;
    string s = "";
    if (n == 1)
    {
        s = "()";
        output.push_back(s);
        return output;
    }
    unordered_map<string,bool>ourMap;
    vector <string> smallOutput = generateParenthesis(n-1);
    
    for(int i = 0 ; i < smallOutput.size(); i++)
    {
        s = smallOutput[i] + "()";
        if(ourMap.count(s) == 0)
        {
            output.push_back(s);
            ourMap[s] = true;
        }
       
        s = "()" + smallOutput[i];
        if (ourMap.count(s) == 0)
        {
            output.push_back(s);
            ourMap[s] = true;
        }
        s = "(" + smallOutput[i] + ")";
        if (ourMap.count(s) == 0)
        {
            output.push_back(s);
            ourMap[s] = true;
        }
    }
    // return output;
    vector<string>b{ "()()()()", "(()()())", "(()())()", "()(()())", "((()()))", "(())()()", "()(())()", "((())())", "()()(())", "(()(()))", "((()))()", "()((()))", "(((())))" };
}