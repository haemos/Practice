### 题目
搜索旋转数组。给定一个排序后的数组，包含n个整数，但这个数组已被旋转过很多次了，次数不详。请编写代码找出数组中的某个元素，假设数组元素原先是按升序排列的。若有多个相同元素，返回索引值最小的一个。


### 思路
因为是旋转数组，必然有一半是有序得，然后不断在有序边进行二分查找即可，注意重复元素的处理

### 代码
~~~ c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int l = 0, r = nums.size()-1, mid, mid2;
        while(l<r){
            while(nums[l]==nums[r] && r>l) r--;//首先去除最右边的重复元素
            mid = (l+r)/2;
            if(mid+1<=r){                     //将划分边界上重复的数字全部滑向右边     
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
        if(nums[l] == target) return l;
        else return -1;
    }
};

~~~
