//
//  LeetCode_6_ZigZagConversion.cpp
//  arithmetic
//
//  Created by li on 2018/5/23.
//  Copyright © 2018年 li. All rights reserved.
//
//原题
//
//　　The string “PAYPALISHIRING” is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//　　P A H N
//　　APLSIIG
//　　Y I R
//　　And then read line by line: “PAHNAPLSIIGYIR”
//　　Write the code that will take a string and make this conversion given a number of rows:
//　　string convert(string text, int nRows);
//　　convert(“PAYPALISHIRING”,3) should return “PAHNAPLSIIGYIR”.
//题目大意
//
//　　输入一个字符串和指定的行数，将字符以Z字型（平躺着的Z）输出。
//分析：
//数据排列
//    p a h n
//    aplsiig
//    y i r
//索引排列
//    0 4 8   12
//    13579 1113
//    2 6 10
//间距与行数的规律： size = 2 * （row - 1）
//索引的规律分两种情况：1.在间距列的规则 index = j+=size ；2.不在间距列的规则 index = j + size -2 * i;


#include "LeetCode_6_ZigZagConversion.hpp"


std::string LeetCode_6_ZigZagConversion::convert(std::string s, int numRows) { 
    if(numRows <= 1) return s;
    string res = "";
    int size = 2 * (numRows -1);//索引间距
    for (int i = 0; i< numRows; ++i) {
        for (int j = i;  j< s.size(); j+=size) {//j+=size 在纵向间距列的规则0 1 2 4 5 6 8 9 10 12 13
            res += s[j];
            int temp = j + size -2 * i;//j + size -2 * i不在纵向间距列的索引规律 3 7 11
            if(i != 0 && i != numRows - 1 && temp < s.size()){//除第一行和最后一行之外，都满足temp规律的索引
                res += s[temp];
            }
        }
    }
    return res;
}


int LeetCode_6_ZigZagConversion::main(int argc, const char *argv[]) {
    
    string s = "paypalishiring";
    string res = LeetCode_6_ZigZagConversion().convert(s, 4);
    cout<<res<<endl;
    return 0;
}
