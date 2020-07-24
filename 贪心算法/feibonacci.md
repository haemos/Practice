### 题
给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。

### 思路
贪心算法，局部取最优解达到最优解。此题首先生成小于K得Fibonacci 数，然后首先取小于K得最大解，k减去他后
再取此时得最大解。

### 代码。
~~~ c++
#include<iostream>
#include<vector>

using namespace std;

class solution {
public:
	int findMinFibonacciNumber(int k) {
		vector<int> nums;
		nums.insert(nums.end(), 2, 1);
		int flag = 0;
		for (int i = 0; flag < k; i++) {
			flag = nums[i] + nums[i + 1];
			if (flag <= k)
				nums.push_back(flag);
			else
				break;
		}
		int N = nums.size();
		int count = 0;
		for (int i = N-1; k > 0; i--) {
			if (k < nums[i]) {
				continue;
			}
			else {
				k -= nums[i];
				count++;
			}
		}

		return count;
		
	}
};

int main(void) {
	solution sol;
	int k,a;
	cin >> k;
	a = sol.findMinFibonacciNumber(k);
	cout << a;
	return 0;
}
~~~
