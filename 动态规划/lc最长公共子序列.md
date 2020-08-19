### 题目
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

### 思路
利用动态规划，定义一个dp数组 dp[i][j] 存放 text1 0~i,text2 0~j有多少个相同的字母。 因此数组的最右下角 也就是 dp[length1][length2]得到最大公共子序列的长度
[referende](https://leetcode-cn.com/problems/longest-common-subsequence/solution/dong-tai-gui-hua-zhi-zui-chang-gong-gong-zi-xu-lie/)

### code 
~~~ c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.length(), length2 = text2.length();
        std::vector<int> temp(length2 + 1, 0);
        std::vector<std::vector<int>> dp(length1 + 1, temp);

        for (int i = 1; i < length1 + 1; i++) {
            for (int j = 1; j < length2 + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[length1][length2];
    }
};
~~~
