//
//  LeetCode_12_IntegerToRoman.cpp
//  arithmetic
//
//  Created by li on 2019/4/28.
//  Copyright © 2019 li. All rights reserved.
//
//罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

#include "LeetCode_12_IntegerToRoman.hpp"
#include <vector>

int LeetCode_12_IntegerToRoman::main(int argc, const char **argv){
    LeetCode_12_IntegerToRoman leetCode12;
//    cout<<leetCode12.intToRoman(1988)<<":"<<leetCode12.intToRoman(06)<<":"<< leetCode12.intToRoman(12) <<endl;
//    cout<<leetCode12.intToRoman(1989)<<":"<<leetCode12.intToRoman(06)<<":"<< leetCode12.intToRoman(17) <<endl;
//    cout<<leetCode12.intToRoman(656)<<":"<< leetCode12.intToRoman(463) <<endl;
    for(int i=1;i<=1000;i++){
       cout<<leetCode12.intToRoman(i) <<endl;
    }
    
    return 1;
}

string LeetCode_12_IntegerToRoman::intToRoman(int num){
    string res = "";
    vector<string> v1{"","M","MM","MMM"};
    vector<string> v2{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> v3{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> v4{"","I","II","III","IV","V","VI","VII","VIII","IX"};
    return v1[num/1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
}
