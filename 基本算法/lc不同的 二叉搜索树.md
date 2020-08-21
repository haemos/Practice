### 题目
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \

### 思路
[reference](https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/)
利用动态规划的思想，首先求N结点时，多少种二叉树，可以是看遍历每一个数字，分别以他为根节点时有多少种，然后加和。而每一个结点的数量，又可以是，他左边有多少个结点的数量乘以他右边有多少个结点的数量

### 代码
~~~ c++
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
~~~
