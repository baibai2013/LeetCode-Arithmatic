//
//  LeetCode_2_AddTwoNumbers.hpp
//  arithmetic
//  
//  Created by li on 2018/4/9.
//  Copyright © 2018年 li. All rights reserved.
//

#ifndef LeetCode_2_AddTwoNumbers_hpp
#define LeetCode_2_AddTwoNumbers_hpp

#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LeetCode_2_AddTwoNumbers{
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    static ListNode* addNode(ListNode* node,int value);
    static int main(int argc, const char * argv[]);
};
#endif /* LeetCode_2_AddTwoNumbers_hpp */
