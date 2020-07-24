/*一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

当数组为全由时返回最大值加一如【0】 返回1，【0，1】 返回2.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int N=nums.size();
    int i;
    for( i=0;i<N;i++){
        if(nums[i]!=i)
            break;
    }
    return i;
    }
};
