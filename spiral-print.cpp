#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
void spiralPrint(int **input, int nRows, int nCols)
{
    int top = 0;//first row
    int down = nRows-1;//bot row
    int left = 0;//first col
    int right = nCols-1;
    int dir = 0;
    while(top <= down && left <= right)
    {
        if(dir == 0)
        {
        for(int i = left ; i <= right; i++)
        {
            cout<<input[top][i]<<" ";
        }cout<<endl;
        top++;
        }
        if(dir==1)
        {
            for(int i = top; i <= down; i++)
            {
                cout<<input[i][right]<<" ";
            }cout<<endl;
            right--;

        }
        if(dir == 2)
        {
            for(int i = right ; i >= left; i--)
            {
                cout<<input[down][i]<<" ";
            }cout<<endl;
            down--;
        }
        if(dir == 3)
        {
            for(int i = down; i >= top; i--)
            {
                cout<<input[i][left]<<" ";
            }cout<<endl;
        }
        dir = (dir+1)%4;
    }
}
int main()
{
    int row, col;
    cin >> row >> col;
    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    spiralPrint(matrix, row, col);
}