### 题目
给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。

### 思路
运用二分的思路，首先将给的数组排序，然后二分最大值，算出小于这个值时的距离对和K进行比较，最后得出结果

### 代码
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int left = 0, right = nums[nums.size() - 1] - nums[0], count = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            int j = 0;
            int count=0;
            for (int i = 1; i < N; i++) {
                while (nums[i] - nums[j] > mid)j++;
                    count += i - j;
            }
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
~~~
