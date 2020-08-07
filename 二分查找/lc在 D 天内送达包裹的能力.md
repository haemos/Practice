### 题目
传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 


### 思路
货物的运载能力肯定在最重的包裹和总包裹重量之间，故对他二分

### 代码
~~~ c++
class Solution {
public:
    int shipWithinDays(vector<int>& nums, int D) {
        int l = *max_element(nums.begin(), nums.end());
    	int r = accumulate(nums.begin(), nums.end(), 0); //等于全部数字的和
    	int ans = 0;
    	while (l <= r) {      //此处只能用<= 针对只能运一次的边界情况。
    		int mid = (l + r) >> 1;
    		int sum = 0,count=0;
    		for (int i = 0; i < nums.size(); i++) {
    			sum += nums[i];
    			if (sum > mid) {
    				sum = 0;
    				i--;
    				count++;
    			}
    			else if (i == nums.size()-1)
    				count++;
    		}
    		if (count<=D) {
    			ans = mid;
    			r = mid-1;
    		}
    		else
    			l = mid + 1;
	    }
    return ans;
    }
};
~~~
