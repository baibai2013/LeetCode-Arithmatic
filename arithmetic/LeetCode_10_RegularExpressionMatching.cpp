//
//  LeetCode_10_RegularExpressionMatching.cpp
//  arithmetic
//
//  Created by li on 2019/4/15.
//  Copyright © 2019 li. All rights reserved.
//
//10.正则表达式匹配
//给定一个字符串（s）和一个字符模式(p)。实现支撑'.'和‘*’的正则表达式匹配。
//'.'匹配任意单个字符
//'*'匹配零个或多个前面的元素。
//匹配应该覆盖整个字符串（s）,而不是部分字符串。
//示例：1
//      s="aa"
//      p="a"
//输出 false
//示例：2
//      s=“aa”
//      p="a*"
//输出  true
//示例：3
//      s="ab"
//      p=".*"
//输出:   true

#include "LeetCode_10_RegularExpressionMatching.hpp"



bool LeetCode_10_RegularExpressionMatching::isMatch(string s, string p){
    if(p.empty()) return s.empty();
    if(p.size() == 1){
        return (s.size() == 1 && (s[0] == p[0] || p[0]=='.'));
    }
    
    if(p[1] != '*'){
        if(s.empty()) return false;
        return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
    
    while(!s.empty() && (s[0] == p[0] || p[0] == '.')){
        if(isMatch(s, p.substr(2))) return true;
        s = s.substr(1);
    }

    return isMatch(s, p.substr(2));
    
}


int LeetCode_10_RegularExpressionMatching::main(int argc, const char **argv){
    LeetCode_10_RegularExpressionMatching leetCode_10_RegularExpressionMatching;
    cout << "isMatch:" << leetCode_10_RegularExpressionMatching.isMatch("aa", "a*") << endl;
    return 0;
}

