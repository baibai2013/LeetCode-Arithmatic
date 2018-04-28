//
//  LeetCode_4_MedianOfTwoSortedArrays.cpp
//  arithmetic
//
//  Created by li on 2018/4/16.
//  Copyright © 2018年 li. All rights reserved.
//
//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
//
//请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
//
//示例 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//中位数是 2.0
//示例 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//中位数是 (2 + 3)/2 = 2.5
//中位数的介绍：https://baike.baidu.com/item/中位数/3087401?fr=aladdin
//n为奇数时，M0.5 = X((n+1)/2) 偶数时，M0.5=（（X(n/2)+X(n/2+1)）/ 2
//         中间的数                        中间两个数和的1/2

//解题思路：
//  类二分查找分

#include "LeetCode_4_MedianOfTwoSortedArrays.hpp"

double LeetCode_4_MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    
    int m = (int)nums1.size(),n = (int)nums2.size();
    if(m<n) return findMedianSortedArrays(nums2, nums1);
    if(n == 0) return ((double)nums1[(m-1) /2] + (double)nums1[m /2]) / 2.0;
    int left = 0, right = n* 2;
    while(left<=right){
        int mid2 = (left + right) /2;
        int mid1 = m+n -mid2;
        double L1 = mid1==0 ? INT_MIN : nums1[(mid1 - 1) / 2];
        double L2 = mid2 ==0 ? INT_MIN : nums2[(mid2 -1) /2];
        double R1 = mid1 == m*2 ? INT_MAX : nums1[mid1 /2];
        double R2 = mid2== n*2 ? INT_MAX:nums2[mid2 / 2];
        if(L1 > R2) left = mid2 + 1;
        else if(L2 > R1) right = mid2 - 1;
        else return (max(L1,L2)+min(R1,R2)) /2 ;
    }
    return -1;
    
}

int LeetCode_4_MedianOfTwoSortedArrays::main(int argc, const char * argv[]){
    
    vector<int> numbs1 = {1,2,4};
    vector<int> numbs2 = {5,6,8};
    double result = LeetCode_4_MedianOfTwoSortedArrays().findMedianSortedArrays(numbs1, numbs2);
    std::cout<<"number:"<<result<<std::endl;
    
    
    return 1;
}
