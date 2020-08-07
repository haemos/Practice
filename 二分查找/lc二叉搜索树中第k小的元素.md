### 题目
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

### 思路
中序遍历则是排序

### 代码
~~~ c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>m;
    void func(TreeNode* root){
        if(root==nullptr)return;
        func(root->left);
        m.emplace_back(root->val);
        func(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        func(root);
        return m[k-1];
    }
};
