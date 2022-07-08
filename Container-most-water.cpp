#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
// int area(vector<int>&height)
// {
//     // int l = 0;
//     // //starting from 0 index 
//     // int r = l+1;
//     //measuring area of each rod after that
//     int area = 0;
//     int subMax = INT_MIN;
//     for(int i = 0 ; i < height.size()-1; i++)
//     {
        
//         int l = i;
//         for(int j = i+1; j < height.size(); j++)
//         {
            
//             int r =  j;
//             area = (r-l)* min(height[r],height[l]);
//             if (area > subMax)
//             {
//                 subMax = area;
//             }
//         }

        
//     }
//     return subMax;
//     // 54/60 passed
// }
int arMax(vector<int>height)
{
    
    
    int l = 0;
    int r = height.size()-1;
    int area = INT_MIN;
    int subArea = 0;
    while(l < r)
    {
    if(height[r] < height[l])
    {
        subArea = (r-l)*height[r];
        area = max(area,subArea);
        r--;
        continue;
        
    }
    else{
        subArea = (r-l)*height[l];
        area = max(area,subArea);
        l++;
        continue;

    }
    }
    return area;
    // int area = INT_MIN;
    // for(int i = 0 ; i < height.size()-1; i++)
    // {
    //     for(int j = i+1; j < height.size(); j++)
    //     {
    //         int length = j-i;
    //         int breadth = min(height[i],height[j]);
    //         area = max(area,length*breadth);

    //     }
    // }
    // return area;
}
// int maxArea(vector<int>height)
// {
//     int subMax = INT_MIN;
//     int area = 0;
//     // GREEDY 2 POINTER OPTIMISED APPROACH
//     int l = 0;
//     int r = height.size() - 1;
//     int max_area = INT_MIN;
//     while (l < r)
//     {
//         if(height[l] <= height[r])
//         {
//             area = (r-l)*height[l];
          
//             l++;
            
        
//         }
//         else{
//             area = (r-l)*height[r];
        
//             r--;
            
           
//         }
//         max_area = max(area,max_area);
//     }
//     return max_area;
// }
// int maxArea(vector<int>height)
// {
//     if(height.size() == 0)
//     return 0;

   
//     int subMax = INT_MIN;
//     int l = 1;
//     int r = l+1;
//     int area_1 = 0;
//     int area_2 = 0;
//     while(l < r && r < height.size()-1)
//     {
//         area_1 = (r-l)*min(height[r],height[l]);
//         int min_height = min(height[r],height[l]);
//         if(min_height == height[r])
//         {
//             if(height[r+1] > height[l])
//             {
//                 r++;
//             }
//         }

        
//         // area = (r-l)*min(height[r],height[l]);
//         // area_2 = (r+1-l)*min(height[r+1],height[l]);
//         // if(area < area_2)
//         // {
//         //     subMax = area_2;
//         //     r++;
            

//         // }
//         // else{
//         //     subMax = area;
//         //     r++;
//         //     l++;
//         // }
        
//     }
//     //Trying the 2 pointer approach
//     return subMax;
// }
int main()
{
    vector<int> a{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout<<arMax(a)<<endl;
}