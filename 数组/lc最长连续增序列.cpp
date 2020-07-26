/*给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int pos=0,n=nums.size(),res=0;
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i-1] >= nums[i]) pos = i;       //小于前面则讲pos移到此处
            res = max(res, i-pos+1);    //比较上一次与现在pos位置减去上一次得到长度。
        }
        return res;
    }
};
