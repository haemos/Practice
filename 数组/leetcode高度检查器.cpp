/*学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。

请你返回能让所有学生以 非递减 高度排列的最小必要移动人数。

注意，当一组学生被选中时，他们之间可以以任何可能的方式重新排序，而未被选中的学生应该保持不动。

 

示例：

输入：heights = [1,1,4,2,1,3]
输出：3 
解释：
当前数组：[1,1,4,2,1,3]
目标数组：[1,1,1,2,3,4]
在下标 2 处（从 0 开始计数）出现 4 vs 1 ，所以我们必须移动这名学生。
在下标 4 处（从 0 开始计数）出现 1 vs 3 ，所以我们必须移动这名学生。
在下标 5 处（从 0 开始计数）出现 3 vs 4 ，所以我们必须移动这名学生。

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	
	void shellsort(vector<int> &heights) {
		int increase, tmp, j, i;
		int size = heights.size();
		for (increase = size / 2; increase > 0; increase /= 2) {
			for (i = increase; i < size; i++) {
				tmp = heights[i];
				for (j = i; j >= increase; j -= increase) {
					if (tmp < heights[j - increase])
						heights[j] = heights[j - increase];
					else
						break;
				}
				heights[j] = tmp;
			}
		}
	}

	int heightChecker(vector<int>& heights) {
		int flag = 0;
		int size = heights.size();
		vector<int> copy_nums(heights);
		shellsort(copy_nums);
		for (int i = 0; i < size; i++)
			if (copy_nums[i] != heights[i]) {
				flag++;
			}
		return flag;
	}
};

int main(void) {
	int a;
	vector<int> heights = {1,1,1,1,1,1 };
	Solution sol;
	a = sol.heightChecker(heights);
	cout << a;
	return 0;
}
