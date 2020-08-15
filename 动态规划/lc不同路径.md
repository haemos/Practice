### 题目
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

<https://leetcode-cn.com/problems/unique-paths/>

### 代码
class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }   
    int uniquePaths(int m, int n) {
        int ans = m + n - 2;        
        int a = 1, b = 1, l = n - 1;     
        for (int i = 1; i <= n - 1; i++)
        {
            a *= ans;
            ans--;
            b *= l;
            l--;
            int g = gcd(a, b);     
            a /= g;              
            b /= g;               
        }
        return a / b;
    }
};
