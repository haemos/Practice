### 题目
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

### 乐扣所有股票问题思路
强烈建议参考 <https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-2/>

### 核心代码详解
~~~ c++
int N = prices.size();
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < N; i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);  
			dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
		}
		return dp_i_0 ;
~~~
+ INT_MIN 是一个常量代表int类型能表达得最小数。

+ dp_i_0代表没买入状态  dp_i_1代表此时是买入状态。

+ dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]) 因为要到达这一步不是买入状态 可能是上一步没买入 也可能是上一步卖出了。因此用max比较上一步哪一个可以得到最大利润后给到此时。

+ dp_i_1 = max(dp_i_1, temp - prices[i] - fee) 这个类似此时买入状态 则可能上一步也是买入，也可能上一步买入。上一步买入则需要剪掉手续费 在卖出减也可。

+ return dp_i_0 肯定最后卖出才能得到最大利润。

~~~ c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices,int fee) {
		int N = prices.size();
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < N; i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);  
			dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
		}
		return dp_i_0 ;
	}
};

int main(void) {
	int a,fee;
	vector<int>prices = { 1,3,2,8,4,9 };
	Solution sol;
	cin >> fee;
	a = sol.maxProfit(prices,fee);
	cout << a;
	return 0;
}
~~~
