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
#include <ios>
#include <stack>
using namespace std;

using namespace std;

//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//单链表
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

#pragma mark - 1 二位数组中的查找
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

#pragma mark - 2 替换空格
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
#pragma mark - 3 从尾到头打印链表
/**
 *
 problem:从头到尾打印链表:输入一个链表，从尾到头打印链表每个节点的值。。
 
 * solution:
 
 
 */



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
#pragma mark - 4 重建二叉树
/**
 *
 problem:
 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */


TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    int in_size =  vin.size();
    if (in_size == 0) {
        return NULL;
    }
    
    vector<int> pre_left,pre_right,in_left,in_right;
    //创建根节点，根节点肯定是前序遍历的第一个数
    int rootNodeValue = pre[0];
    TreeNode *rootNode = new TreeNode(rootNodeValue);
    
    //找到中序遍历根节点所在位置,存放于变量p中
    int p = 0;
    for (p; p < in_size; ++p) {
        if (vin[p] == rootNodeValue) {
            break;
        }
    }
    

    for(int i=0;i<p;i++){           //构建中序序列的左子树和前序序列的左子树
        in_left.push_back(vin[i]);
        pre_left.push_back(pre[i+1]);
    }
    for(int i=p+1;i<in_size;i++){   //构建中序序列的右子树和前序序列的右子树
        in_right.push_back(vin[i]);
        pre_right.push_back(pre[i]);
    }
    
    //递归
    rootNode->left = reConstructBinaryTree(pre_left, in_left);
    rootNode->right = reConstructBinaryTree(pre_right, in_right);

    return rootNode;
}
#pragma mark - 5 用两个栈实现队列
/*
 *用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */
stack<int> stack1;
stack<int> stack2;

//stack1 push
void push(int node) {
    stack1.push(node);
}

//stack2 pop
int pop() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    int value = stack2.top();
    stack2.pop();
    return value;
}

#pragma mark - 6 旋转数组的最小数字
/*
 * 知识点:查找
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */


int minNumberInRotateArray(vector<int> rotateArray) {
    
    if (rotateArray.size() == 0) {
        return 0;
    }
    //二分查找
    int left = 0;
    int right = rotateArray.size() - 1;
    int middle = -1;
    while (rotateArray[left] >= rotateArray[right]) {
        if (right - left == 1) {
            middle = right;
            break;
        }
        middle = left+ (right-left)/2;
        
        if (rotateArray[middle]>=rotateArray[left]) {
            left = middle;
        }else if(rotateArray[right]>=rotateArray[middle]){
            right = middle;
        }
        
    }
    
    
    return rotateArray[middle];
}
#pragma mark - 7 斐波那契数列
/*
 *
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
 */
int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n ==1 || n == 2) {
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

#pragma mark - 8 跳台阶
/*
 *
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
int jumpFloor(int number) {
    
    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    return jumpFloor(number - 1)+jumpFloor(number - 2);
}
#pragma mark - 9 变态跳台阶
/*
 *
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
int jumpFloorII(int number) {
    
    /*
    跳1级，剩下n-1级，则剩下跳法是f(n-1)
    跳2级，剩下n-2级，则剩下跳法是f(n-2)
    所以f(n)=f(n-1)+f(n-2)+...+f(1)
    因为f(n-1)=f(n-2)+f(n-3)+...+f(1)
    所以f(n)=2*f(n-1)
     */
    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    return 2*jumpFloorII(number-1);
}

#pragma mark - 10 矩形覆盖
/*
 *  我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 */
int rectCover(int number) {
    //画图找规律
    if (number <= 0) {
        return 0;
    }else if (number == 1 || number == 2){
        return number;
    }

    return rectCover(number-1)+rectCover(number - 2);
}
#pragma mark - 11 二进制中1的个数
/*
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */
int  NumberOf1(int n) {
    
    //考虑采用二进制的运算求解
    int count = 0;
    while (n != 0) {
        count ++;
        n = n & (n - 1);
    }
    return count;

}

#pragma mark - 12 数值的整数次方
/*
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */
double Power(double base, int exponent) {
    //直接以数学运算表示
    double result = 0;
    if (exponent == 0) {
        return 1;
    }else if (exponent > 0){
        result = base;
        for (int i = 0 ; i < (exponent-1); i ++) {
            result = result * base;
        }
        return result;
    }else{
        result = base;
        exponent = -exponent;
        for (int i = 0 ; i < (exponent-1); i ++) {
            result = result * base;
        }
        return 1/result;
    }
    
}
#pragma mark - 13 调整数组顺序使奇数位于偶数前面
/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
void reOrderArray(vector<int> &array) {
    vector<int> oddNumberArray;     //奇数
    vector<int> evenNumberArray;    //偶数
    
    int arrayLength = (int)array.size();
    for (int i = 0 ; i < arrayLength; i ++) {
        if (array[i]%2 == 0) {
            evenNumberArray.push_back(array[i]);
        }else{
            oddNumberArray.push_back(array[i]);
        }
    }
//    two vector connect
    array.clear();
    oddNumberArray.insert(oddNumberArray.end(), evenNumberArray.begin(), evenNumberArray.end());
    array = oddNumberArray;
}
#pragma mark - 14 链表中倒数第k个结点
/*
 * 输入一个链表，输出该链表中倒数第k个结点。
 */

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (!pListHead || k == 0 ) {
        return NULL;
    }
    
    //将链表反转，存入栈中
    stack<ListNode *> stack;
    while (pListHead) {
        stack.push(pListHead);
        pListHead = pListHead->next;
    }
    
    if (stack.size() < k) {
        return NULL;
    }
    int i = 1;//k从1开始
    while (i < k) {
        stack.pop();
        i++;
    }
    
    return stack.top();
}

#pragma mark - 15 反转链表

/*
 * 输入一个链表，反转链表后，输出新链表的表头
 */
//

ListNode* ReverseList(ListNode* pHead) {
    
    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }
    stack<ListNode *> stack;
    while (pHead->next != NULL) {
        stack.push(pHead);
        pHead = pHead->next;
    }
    
    //从栈中重新构建一个链表
    ListNode *reverseHead = pHead;
    while (!stack.empty()) {
        pHead->next = stack.top();
        pHead = pHead->next;
        stack.pop();
    }
    pHead->next = NULL; //这句话必须，设置
    return reverseHead;
}

#pragma mark - 16 合并两个排序的链表

/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 */
//非递归方法，新建一个链表来代表合并后的链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL && pHead2 != NULL) {
        return pHead2;
    }
    if (pHead1 != NULL && pHead2 == NULL) {
        return pHead1;
    }
    if (pHead1 == NULL && pHead2 == NULL) {
        return NULL;
    }
    
    //确定头结点，新建一个链表来代表合并后的链表，非递归方法
    ListNode *mergeHead;

    if (pHead1->val <=  pHead2->val) {
        mergeHead = pHead1;
        pHead1 = pHead1->next;
    }else{
        mergeHead = pHead2;
        pHead2 = pHead2->next;
    }
    ListNode *tempHead = mergeHead;
    
    //比较两个链表的大小
    while (pHead1 != NULL && pHead2 != NULL) {
        if (pHead1->val <=  pHead2->val) {
            mergeHead->next = pHead1;
            mergeHead = pHead1;
            pHead1 = pHead1->next;
        }else{
            mergeHead->next = pHead2;
            mergeHead = pHead2;
            pHead2 = pHead2->next;
        }
    }
    
    
    if (pHead1 != NULL) {
        mergeHead->next = pHead1;
    }
    if (pHead2 != NULL) {
        mergeHead->next = pHead2;
    }

    return tempHead;
}
#pragma mark - 17 树的子结构
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//树的遍历一般用递归;
bool isSubtree(TreeNode *pRoot1,TreeNode *pRoot2)
{
	if (pRoot2 == NULL) {
		return true;
	}
	if (pRoot1 == NULL) {
		return false;
	}
	return pRoot1->val == pRoot2->val && isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot2 == NULL || pRoot1 == NULL) {
        return false;
    }
    
	return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	
}

#pragma mark - 18 二叉树的镜像
/*
 作给定的二叉树，将其变换为源二叉树的镜像。
 二叉树的镜像定义：源二叉树
 
   8
  /  \
  6   10
 / \  / \
 5  7 9 11
 镜像二叉树
   8
  /  \
 10   6
 / \  / \
 11 9 7  5
 
 */
void Mirror(TreeNode *pRoot) {	//层次遍历，走一下操作流程总结出规律操作即可
	if (pRoot == NULL) {
		return;
	}
	if (pRoot->left == NULL && pRoot->right == NULL) {
		return;
	}
	
	//左右交换
	TreeNode *pTemp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = pTemp;
	
	if (pRoot->left != NULL) {
		Mirror(pRoot->left);
	}
	if (pRoot->right != NULL) {
		Mirror(pRoot->right);
	}
}
#pragma mark - 19 顺时针打印矩阵
/**
 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
 如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

/*
 解题思路:打印一圈分为四步：
 			 第一步：从左到右打印一行
			 第二步：从上到下打印一列;
			 第三步: 从右到做打印一行;
			 第四步：从下到上打印一列;
			 特殊点：最后一圈有可能退化成只有一行、只有一列、甚至只有一个数字;
 但是需仔细分析每一步打印的前提条件;
 
 用start变量标识起始打印点;
 
*/
void printMartrixInCircle(vector<vector<int>> &matrix, int start, vector<int> &ret)
{
	int rows = (int)matrix.size();
	int columns = (int)matrix[0].size();
	int endX = (columns-1)-start;
	int endY = (rows - 1)-start;
	//从左到右
	for (int i = start; i <= endX; ++i) {
		ret.push_back(matrix[start][i]);
	}
	//从上到下，至少两行
	if (endY > start) {
		for (int i = start + 1; i <= endY; ++i) {
			ret.push_back(matrix[i][endX]);
		}
	}
	//从右到左，至少两行两列
	if (endX > start && endY > start) {
		for (int i = endX-1; i >= start; i--) {
			ret.push_back(matrix[endY][i]);
		}
	}
	//从下到上，至少三行两列
	if (endY > start + 1 && endX > start) {
		for (int i = endY-1; i >= start + 1; i--) {
			ret.push_back(matrix[i][start]);
		}
	}
	
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	int rows = (int)matrix.size();
	int columns = (int)matrix[0].size();
	vector<int> ret;//作为结果
	if (matrix.size() == 0 || columns <= 0 || rows <= 0) {
		return ret;
	}
	
	int start = 0;//start+1代表已打印的圈数,
	while (columns > start * 2 && rows > start * 2) {	//确定打印的圈数
		printMartrixInCircle(matrix, start, ret);
		++start;
	}
	return ret;
}

#pragma mark - 20 包含min函数的栈
/**
 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 */

/*
 栈 3 4 2 5 1
 辅助栈 3 3 2 2 1
 每入栈一次，就与辅助栈顶比较，若小就入栈，如果大就入栈当前的辅助栈顶部或者不入保持栈顶不变;
 
 */
stack<int> m_min_stack,m_help_stack;
void min_stack_push(int value) {
	m_min_stack.push(value);
	if (m_help_stack.empty()) {
		m_help_stack.push(value);
	}else if (value <= m_help_stack.top()){
		m_help_stack.push(value);
	}else if (value > m_help_stack.top()){
		m_help_stack.push(m_help_stack.top());
	}
}
void min_stack_pop() {
	m_help_stack.pop();
	m_min_stack.pop();
}
int min_stack_top() {
	return m_min_stack.top();
}
int min_stack_min() {
	return m_help_stack.top();
}

#pragma mark - 剑指 Offer 03. 数组中重复的数字
/*
 *

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/59bjss/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 * 题目解析
 * 方法一： 哈希表/set
 * */
class Solution03 {
public:
    int findRepeatNumber(vector<int> &nums) {
        unordered_map<int, bool> map;
        for (int num:nums) {
            if (map[num]){
                return num;
            } else{
                map[num] = true;
            }
        }
        return -1;
    };
};
/*
 * 方法二：方法二：原地交换
 * 特殊的： 本题主要是值等于索引， 可以使用。
 * 第二种的话，是就题论题，其他题不一定就这样做的，不过思想是好的，就是让索引和索引对应的值相等，就是索引是0，值就是0，索引是1，值就是1。
 * */
class Solution03_2 {
public:
    int findRepeatNumber(vector<int> &nums) {
        int i =0;
        while (i<nums.size()){
            if (nums[i] == i){
                i++;
                continue;
            }
            if (nums[i] == nums[nums[i]]){
                return nums[i];
            }
            swap(nums[i],nums[nums[i]]);

        }
        return -1;
    };
};

#pragma mark - test
void test()
{
//    swordFinger_1_test();
    swordFinger_2_test();
}
