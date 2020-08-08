### 题目
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true


### 思路
单传遍历为N 用二分logn  因为是旋转数组，肯定左边和右边有一个是有序的。

### 代码
~~~ c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        int l = 0, r = nums.size()-1, mid, mid2;
        while(l<r){
            while(nums[l]==nums[r] && r>l) r--;//首先去除最右边的重复元素    避免当131这种情况时出现bug
            mid = (l+r)/2;
            if(mid+1<=r){                     //将划分边界上重复的数字全部滑向右边     加快运算速度，避免无意义循环。
               int temp = nums[mid+1];
               for(int i=mid;i>=l;i--){
                   if (nums[i]!=temp){
                       mid = i;
                       break;
                   }
               }
            }
            if(nums[l]<=nums[mid]){ //左边有序，先看左边
                if(target>=nums[l] && target<=nums[mid]) r = mid;
                else l = mid+1;
            }
            else{                   //右边有序，先看右边
                if(target>=nums[mid+1] && target<=nums[r]) l = mid+1;
                else r = mid;
            }
        }
        if(nums[l] == target) return true;
        else return false;
    }
};
~~~
