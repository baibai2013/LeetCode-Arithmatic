//
//  LeetCode_11_ContainerWithMostWater.cpp
//  arithmetic
//
//  Created by li on 2019/4/16.
//  Copyright © 2019 li. All rights reserved.
//给定n个非负整数a1,a2,...,an,每个数代表坐标中的一个点(i,ai),在坐标内画n条垂直线，垂直线i两端点分别为（i，ai）和（i，0）。找出其中的两条线，使得他们与x轴
//共同构成的容器可以容纳最多的水。

//说明：你不能倾斜容器，且n的值不能小于2。

//示例：
//输入： [1,8,6,2,5,4,8,3,7]
//输出：49

#include "LeetCode_11_ContainerWithMostWater.hpp"
#include <vector>

int LeetCode_11_ContainerWithMostWater::maxArea(vector<int> &height){
    int res = 0, i = 0,j = height.size()-1;
    //直到不成容器
    while(i<j){
        //用最短的一条直线的高*宽度得到容器的容量
        res = max(res, min(height[i], height[j]) * (j-i));
        //如果左边比小向➡️走1，否则右边向⬅️走1
        height[i] < height[j] ? ++i : --j;
    }
    return res;
}


int LeetCode_11_ContainerWithMostWater::main(int argc, const char **argv){
    
    LeetCode_11_ContainerWithMostWater leetCode11;
    
    int  heights[] = {1,8,6,2,5,4,8,3,7};
    vector<int> heightsVector(heights,heights+9);
    cout<<"容量："<<leetCode11.maxArea(heightsVector)<<endl;
    return 1;
}
