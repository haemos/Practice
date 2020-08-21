### 题目
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

### 思路
令拿一个数组，当碰到大于末尾元素时，添加进数组，当碰到比末尾小的时候，用二分法在新数组中查找所在区间，然后替换(虽然这样值可能会不符合上升，但是序列长度是一样)
因为如果后面有比刚加的大但是小于末尾的 又会在刚加的数后面选一个进行替换。

### 代码
~~~ c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N=nums.size();
        if(N==0)return 0;
        vector<int> dp(N+1);
        int len=0;
        dp[++len]=nums[0];
        for(int i=0;i<N;i++){
            if(nums[i]>dp[len])dp[++len]=nums[i];
            else{
                int left=1,right=len;
                while(left<=right){
                    int mid=(right+left)>>1;
                    if(dp[mid]<nums[i]){
                        left=mid+1;
                    }
                    else{
                        right=mid-1;
                    }
                }
                dp[left]=nums[i];
            }
        }
        return len;
    }
};
~~~
