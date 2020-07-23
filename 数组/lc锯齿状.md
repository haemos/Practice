### 题目
  给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：

每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。

### 核心思路
**选择递减两边最优解，因为递减两边使得下一个更容易符合条件。**

### 代码

~~~ c++
#include<iostream>
#include<vector>
#include<algorithm>		//存有min.

using namespace std;

class Solution {
public:
	int N;
	int compute(vector<int>& nums, int idx) {
		int count = 0;
		for (; idx < N; idx += 2) {
			int current = nums[idx];
			if (idx > 0 && nums[idx - 1] >= current) {		//处理N-1时		
				count += nums[idx - 1] - current + 1;
				nums[idx - 1] = current - 1;
			}
			if (idx + 1 < N && nums[idx + 1] >= current) {	//处理0
				count += nums[idx + 1] - current + 1;		// 将右边数减到比本身小一。
				nums[idx + 1] = current - 1;
			}
		}
		return count;
	}
	int movesTomakeZigazg(vector<int>& nums) {
		N = nums.size();
		vector<int> copy(nums);		//复制一遍数组，方遍奇偶判断。
		return min(compute(copy, 0), compute(nums, 1)); 	//比较奇偶分别需要的步数大小。调试发现：
	}														//	先执行compute(nums.1)个人理解类似于汇编后面参数先传。
};

int main(void) {
	vector<int> nums = { 2,7,10,9,8,9 };
	int a;
	Solution sol;
	a = sol.movesTomakeZigazg(nums);
	cout << a;
	return 0;
}
~~~
