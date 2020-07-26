/*峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

时间得是logn(明显二分查找)

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
        {
            return -1;
        }

        if (nums.size() == 1 || nums.at(0) > nums.at(1))
        {
            return 0;
        }

        if (nums.at(nums.size() - 1) > nums.at(nums.size() - 2))
        {
            return nums.size() - 1;
        }

        int left = 1;
        int right = nums.size() - 2;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums.at(mid - 1) > nums.at(mid))
            {
                right = mid - 1;
            }
            else if (nums.at(mid + 1) > nums.at(mid))
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return left;
    }
};
