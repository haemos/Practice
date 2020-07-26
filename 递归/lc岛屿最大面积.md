### 题目
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

### 思路
循环遍历 当碰到1时对四周进行递归探测。

### 核心代码与重点。
~~~ c++
	int checkaround(vector<vector<int>>& grid, int x, int y, int N, int M) {
		int count = 1;
		grid[x][y] = 0;  //用过得清零。
		if (x - 1 >= 0 && grid[x-1][y] == 1) {		//往上
			count+=checkaround(grid, x - 1, y, N, M);
		}if (x + 1 <N && grid[x + 1][y] == 1) {
			count += checkaround(grid, x + 1, y, N, M);		//往下
		}if (y - 1 >= 0 && grid[x][y - 1] == 1) {
			count += checkaround(grid, x, y - 1, N, M);		//往左
		}if (y + 1 < M && grid[x][y + 1] == 1) {				
			count += checkaround(grid, x, y + 1, N, M);		//往右。
		}
		return count;
	}
  ~~~
  #### vector容器定义二维数组写法 vector<vector<int>>.

### 代码
~~~ c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int checkaround(vector<vector<int>>& grid, int x, int y, int N, int M) {
		int count = 1;
		grid[x][y] = 0;  //用过得清零。
		if (x - 1 >= 0 && grid[x-1][y] == 1) {		//往上
			count+=checkaround(grid, x - 1, y, N, M);
		}if (x + 1 <N && grid[x + 1][y] == 1) {
			count += checkaround(grid, x + 1, y, N, M);		//往下
		}if (y - 1 >= 0 && grid[x][y - 1] == 1) {
			count += checkaround(grid, x, y - 1, N, M);		//往左
		}if (y + 1 < M && grid[x][y + 1] == 1) {				
			count += checkaround(grid, x, y + 1, N, M);		//往右。
		}
		return count;
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int N = grid.size();
		int count = 0,sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <grid[i].size() ; j++) {
				if (grid[i][j] == 0)continue;
				else {
					count = checkaround(grid, i, j, N, grid[i].size());
					count > sum ? sum = count : sum = sum;
				}
			}
		}
		return sum;
	}
};


int main(void) {
	vector<vector<int>> grid = {
	{ 0,0,1,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,1,1,0,1,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,1,1,0,0,1,0,1,0,0 },
	{ 0,1,0,0,1,1,0,0,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,0,0 }
	};
	int a;
	Solution sol;
	a = sol.maxAreaOfIsland(grid);
	cout << a;
	return 0; 
}
~~~
