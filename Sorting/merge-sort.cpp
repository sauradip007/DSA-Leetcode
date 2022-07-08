#include <bits/stdc++.h>
using namespace std;
void merge(int input1[],int size1,int input2[], int size2)
{
    int i = 0 ; j = 0 , k = 0;
    while(i < size1 && j < size2)
    {
        if(input1[i] < input2[j])
        {
            output[k] = input1[i];
            k++;
            i++;
        }
        else{
            output[k] = input2[j];
            k++;
            j++; 
        }
    }
    while(i < size1)
    {
        output[k] = input1[i];
        k++;
        i++;
    }
    while(j < size2)
    {
        output[k] = input2[j];
        k++;
        j++;
    }
}
void mergeSort(int input[], int size)
{
    if(size <= 1)
    return;
    int mid = size/2;
    int part1[500];
    int part2[500];
    for(int i = 0 ; i < mid; i++)
    {
        part1[i] = input[i];
    }
    int k = 0;
    for(int i = mid; i < size; i++)
    {
        part2[k] = input[i];
        k++;
    }
    int size1 = mid;
    int size2 = size-mid;
    mergeSort(part1,size1);
    mergeSort(part2,size2);
    merge(part1,size1,part2,size2);
}
int main()
{
    
}