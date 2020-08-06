### 题目
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

输入: [1,3,4,2,2]
输出: 2

### 思路
因为数字都在1到n之间，用count表示nums数组中小于i的数量，当i小于重复数时，count<=i，当i>=重复值时，count>i

### 代码
~~~ c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N=nums.size();
        if(N==0)return 0;
        int l=1,r=N-1,ans=0;
        while(l<=r){
            int count=0;
            int mid=(r+l)>>1;
            for(int i=0;i<N;i++){
                if(nums[i]<=mid)
                    count++;
            }
            if(count<=mid)
                l=mid+1;
            else{
                r=mid-1;
                ans=mid;    //保存结果值。
            }        
        }
        return ans;
    }
};
~~~
