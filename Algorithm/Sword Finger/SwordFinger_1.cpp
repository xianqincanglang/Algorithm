//
//  SwordFinger_1.cpp
//  Algorithm
//
//  Created by chentianyu on 2018/5/28.
//  Copyright © 2018年 chentianyu. All rights reserved.
//

#include "SwordFinger_1.hpp"
#include <vector>
#include <iostream>
using namespace std;

#pragma mark - 1
/**
 *
 problem:在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * solution:
 比较数组右上角数字和标准数:
    若等于，返回true;
    若小于标准数，删除该行;
    若大于标准数,删除该列;
 通过该比较缩小查找范围，直到找到该数字，或者找不到该数字
 */

bool swordFinger_1(vector<vector<int>> array,int target)
{
    int rowCount = (int)array.size();
    int colCount = (int)array[0].size();
    for (int i = 0, j = colCount-1; i >=0 && i<rowCount; ) {
        if (target == array[i][j]) {
            return true;
        }else if(target < array[i][j]){
            j --;
            continue;
        }else if(target > array[i][j]){
            i ++;
            continue;
        }
    }
    return false;
}
void swordFinger_1_test()
{
    vector<vector<int>> array = {{0,1,2,3},{1,2,3,4},{3,4,5,6}};
    int target = 5;
    cout << "result:"<< swordFinger_1(array, target) << endl;
    
}

#pragma mark - 2
/**
 *
 problem:替换空格:请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 
 * solution:
    string中应该有对应的系统方法

 */

void swordFinger_2(char *str,int length)
{
    //length的作用
    int spaceNum = 0;
    for (int i = 0 ; i < length; i ++) {
        if (str[i] == ' ') {
            spaceNum ++;
        }
    }
    int newIndex = length + 2 * spaceNum;
    
    //开始填入
    char *index = str + length;
    
    while (index >= str) {
        if (*index == ' ') {
            str[newIndex--] = '0';
            str[newIndex--] = '2';
            str[newIndex--] = '%';
        }else{
            str[newIndex --] = *index;
        }
        index --;
    }

}
void swordFinger_2_test()
{
    string str = "We Are Happy";
    char *c = const_cast<char *>(str.c_str());  //str转char *
    swordFinger_2(c, str.length());
    
    cout << c << endl;
}
#pragma mark - 3
/**
 *
 problem:从头到尾打印链表:输入一个链表，从尾到头打印链表每个节点的值。。
 
 * solution:
 
 
 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
   }
};

vector<int> printListFromTailToHead(ListNode* head) {
    //先将值push_back到vector
    vector<int> vector;

    if (head != NULL) { //注意为null的判断
        vector.push_back(head->val);
        ListNode* node = head->next;
        while (node) {
            vector.push_back(node->val);
            node = node->next;
        }
    }
    
    //反转vector
    std::reverse(vector.begin(), vector.end());

    
    return vector;
}

void swordFinger_3_test()
{
    
}
#pragma mark - test
void test()
{
//    swordFinger_1_test();
//    swordFinger_2_test();
    swordFinger_3_test();
    
}
