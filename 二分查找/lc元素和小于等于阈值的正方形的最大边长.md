### 题目
给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。

请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。

输入：mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
输出：2
解释：总和小于 4 的正方形的最大边长为 2。

### 思路
先对二位数组预处理，构建二维前缀和数组，然后在二分边长和threshold进行比较。
二维数组前缀和参考这两个帖子  
[一维和二维数组前缀和](https://blog.csdn.net/codeswarrior/article/details/78117051)  
[leetcode题解](https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/solution/yuan-su-he-xiao-yu-deng-yu-yu-zhi-de-zheng-fang-2/)

### 代码
~~~ c++
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int N = mat.size();
	    int N1 = mat[0].size();
	    vector<vector<int>>p(N + 1, vector<int>(N1 + 1));
    	for (int i = 1; i <= N; i++) {
	    	for (int j = 1; j <= N1; j++) {
	    		p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + mat[i-1][j-1];      //从11开始填入到1，1之间的矩阵的和。
	    	}
    	}
    	int l = 1, r = min(N, N1),ans=0;
    	while (l <= r) {
    		int mid = (l + r) >> 1;
	    	bool flag = false;
		    for (int i = 1; i <= N - mid + 1; ++i) {
			    for (int j = 1; j <= N1 - mid + 1; ++j) {   //遍历所有边长为k的矩阵，只要有一个小于threshold即可。
				    if (p[i + mid - 1][j + mid - 1] - p[i - 1][j + mid - 1] - p[i + mid - 1][j - 1] + p[i - 1][j - 1] <= threshold) {
					    flag = true;
				    }   
			    }
		    }
    		if (flag) {
	    		ans = mid;
		    	l = mid + 1;
    		}
    		else
    			r = mid - 1;
    	}
     return ans;
    }
};
~~~
