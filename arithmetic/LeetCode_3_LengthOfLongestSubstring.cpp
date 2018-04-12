//
//  LeetCode_3_LengthOfLongestSubstring.cpp
//  arithmetic
//
//  Created by li on 2018/4/11.
//  Copyright © 2018年 li. All rights reserved.
//给定一个字符串，找出不含有重复字符的 最长子串 的长度。
//
//示例：
//
//给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
//
//给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
//
//给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列 而不是子串。
//
//解题思路：
//保存ASCII字符出现的位置如果出现过从新标记开始位置，当前位置和之前出现过的位置的差就是长度了。
//               left
//                |
//                123
//m--------------------------------------------
//                abcd
//
// i
// |
// abcabcbb
//s--------
//
// res = i - left;

#include "LeetCode_3_LengthOfLongestSubstring.hpp"
#include <vector>
#include <stdio.h>
#include <iostream>

int LeetCode_3_LengthOfLongestSubstring::lengthOfLongestSubstring(string s){
    vector<int> m(256,-1);//初始化vector 只考虑ASCII字符
    int res = 0,left = -1;
    for(int i=0; i< s.size();++i){
        left = max(left,m[s[i]]);//如果字符已出现过，就重新标记开始位置
        m[s[i]] = i; //存储当前字符的位置，标记第i个字符被访问过
        res = max(res,i-left);//计算当前长度
    }
    
    return res;
}


int LeetCode_3_LengthOfLongestSubstring::main(int argc, const char * argv[]){
    
    int length = LeetCode_3_LengthOfLongestSubstring().lengthOfLongestSubstring("abcabcbb");
    std::cout << "length:" << length << endl;
    return 0;
}
