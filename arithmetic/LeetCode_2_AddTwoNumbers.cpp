//
//  LeetCode_2_AddTwoNumbers.cpp
//  arithmetic
//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.

//问题描述
//给定两个非空单向链表代表两个非负整数。整数中每一位的数字都逆序存储在链表节点中，求出
//这两个非负整数的和并将结果中的数字以相同的逆序方式存储在一个单项链表中。可以不考虑
//数字前面的0。
//
//例如：输入：(2 -> 4 -> 3) + (5 -> 6 -> 4) 输出 ：7 -> 0 -> 8
//
//思路分析
//用LinkList代表整数中每一个数字，模拟加法进位的方式进行求和计算。例如：2 -> 4 -> 3
//和5 -> 6 -> 4，先计算个位数 2和5的和为7， 十位数 4和6的和为10，逢十进一，则该位的数字
//为0，产生一位进位1到百位参与百位的数字求和。那么百位的结果：3 + 4 + 1（这个1就是刚刚十位
//相加产生的进位），百位计算结果为8，所以最终返回结果 7 -> 0 -> 8

//  Created by li on 2018/4/9.
//  Copyright © 2018年 li. All rights reserved.
//

#include "LeetCode_2_AddTwoNumbers.hpp"
#include <iostream>

ListNode* LeetCode_2_AddTwoNumbers::addNode(ListNode *node, int value){
    node->val = value;
    node->next = new ListNode(0);
    return node->next;
}

ListNode* LeetCode_2_AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode* res = new ListNode(-1);
    ListNode* cur = res;
    int carray = 0; //初始进位；
    while(l1 || l2){//只要一个链表不为空 都进行计算
        int n1 = l1? l1->val : 0; //l1当前 node不为空取它的值，否则为0
        int n2 = l2? l2->val : 0;//l2当前 node不为空取它的值，否则为0
        int sum = n1 + n2 + carray;//当前位相加 如个位 2+7+0
        carray = sum / 10; //进位计算 结果 0 或者 1
        cur -> next = new ListNode(sum % 10); //下一位的值 13 % 10 = 3
        cur = cur -> next;
        if(l1) l1 = l1->next; //l1下一个节点 结果：NULL或者有值
        if(l2) l2 = l2->next;//l1下一个节点 结果：NULL或者有值
    }
    if(carray) cur->next = new ListNode(1); //如果最后一位也进位 添加新节点
    return res->next; //返回结果
}

int LeetCode_2_AddTwoNumbers::main(int argc, const char **argv){
    
    ListNode *l1 = new ListNode(2);
    ListNode *cur = l1;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(3);
    
    ListNode *l2 = new ListNode(5);
    cur = l2;
    cur->next = new ListNode(6);
    cur = cur->next;
    cur->next = new ListNode(4);
    
    ListNode *res = LeetCode_2_AddTwoNumbers().addTwoNumbers(l1, l2);
    
    do{
        std::cout << res->val;
        if(res->next) std::cout << "->";
    }while((res = res->next) );
    
    return 0;
}
