//
//  Test1.cpp
//  Lenrn_Algorithm
//
//  Created by chen tianyu on 2021/6/24.
//

#include "Test1.hpp"
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL){
        
    }
};
struct ListNode{
    int val;
    ListNode *next;
};
void traverse(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->next) {
        // 迭代访问p.val
    }
}

void traverse2(TreeNode *node){
    if (!node) {
        return;
    }
//    traverse2(node->left);
//    if (node->val < ->val) {
//
//    }
}
#pragma mark - fib数列,
////  自顶向下
int helper(vector<int>& memo, int n){
    if (n == 1 || n == 2) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = helper(memo, n-1)+helper(memo, n-2);
    return memo[n];
}
int fib(int N)
{
    if (N<1) {
        return 0;
    }
    
    vector<int> memo(N+1,0);
    return helper(memo, N);
}
///自底向上, 循环迭代
int fibBottomToTop(int N){
    if (N<1) {
        return 0;
    }
    if (N == 1 || N == 2) {
        return 1;
    }
    vector<int> dp(N+1,0);
    ///base
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[N];
}

int coinChange(vector<int>& coins, int amount)
{
    ///数组大小为amout+1, 初始值也为amount+1
    vector<int> dp(amount+1, amount+1);
    dp[0]  = 0;
    for (int i = 0; i < dp.size(); i++) {
        for(int coin:coins){
            if (i - coin < 0) {
                continue;
            }
            dp[i] = min(dp[i], 1+dp[i-coin]);
        }
    }
    return (dp[amount] == amount+1)?-1:dp[amount];
}

//void traverse2(ListNode *head)
//{
//    ///循环访问
//    traverse2(head->next);
//}
//class TreeNode {
//    int val;
////    TreeNode left, right;
//};
//void
