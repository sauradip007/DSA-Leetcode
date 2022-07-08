#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int subset(int input[], int n, int output[][20])
{
    if(n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    int no_col = 0;
    int smallerOutput = subset(input+1,n-1,output);
    for(int i = 0 ; i < smallerOutput; i++)
    {
        no_col = output[i][0];
        output[i+smallerOutput][0] = 1 + output[i][0];
        for(int j = 1; j <= no_col; j++)
        {
            output[i+smallerOutput][j+1] = output[i][j];
        }
        output[i+smallerOutput][1] = input[0];
    }
    return 2*smallerOutput;
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}