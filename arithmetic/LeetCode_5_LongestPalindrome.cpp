//
//  LeetCode_5_LongestPalindrome.cpp
//  arithmetic
//
//  Created by li on 2018/5/15.
//  Copyright © 2018年 li. All rights reserved.
//原题
//
//　　Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000,and there exists one unique longest palindromic substring.
//题目大意
//
//　　给定一个字符串S，找出它的最大的回文子串，你可以假设字符串的最大长度是1000，而且存在唯一的最长回文子串

//解题思路
//  动态规划法:保存处理过程中的状态，从状态中找寻获得数据按条件筛选
//  回文:是指正着读和倒着读，结果一样，比如abcba或abba。
//  s[i,j]（表示以i 开始j结束的字串）是回文字符串，那么s[i+1,j-1]也是回文字符串，这样最长回文字串就可以分解为一系列子问题
//  空间复杂度O（N^2）,时间复杂度O(N^2)
//

#include "LeetCode_5_LongestPalindrome.hpp"
string LeetCode_5_LongestPalindrome::longestPalindrome(string s){
    int dp[s.size()][s.size()],left = 0,right = 0,len = 0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < s.size(); ++i){
        for (int j = 0; j < i; ++j) {
            dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));//如果字母相同 且 子串也相同（状态为1）或者就两个字母，标记相同的字母的状态为1
            if(dp[j][i] && len < i-j+1){//如果找到相同的字母，并且新的长度比之前的长，长度值 字符串开始位置left 和结束为止right改变数据
                len = i-j +1;//index + 1 为长度
                left = j;
                right = i;
            }
        }
        dp[i][i] = 1;
        
//        for(int k=0;k<s.size();k++){//查看状态值
//            for(int n=0;n<s.size();n++){
//            cout<<dp[k][n];
//            }
//            cout<<endl;
//        }
//
//        cout<<endl;
    }
    return s.substr(left,right-left + 1);
    
}

int LeetCode_5_LongestPalindrome::main(int argc, const char * argv[]){
    
    string s = "wetyuytsdfgfds";
    LeetCode_5_LongestPalindrome longestPalindrome;
    string subs = longestPalindrome.longestPalindrome(s);
    std::cout<<"LongestPalindrome:"<< subs <<std::endl;
    
    
    return 0;
}
