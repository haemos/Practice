/*给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        vector<int> new_nums;
        for (int i = 0; i < N; i++) {
            new_nums.emplace_back(i + 1);
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0 || nums[i] < 0)continue;
            if (nums[i] <= N) {
                new_nums[nums[i] - 1] = 0;
            }
            else
                continue;

        }
        for (int i = 0; i < N; i++) {
            if (new_nums[i] != 0)
                return new_nums[i];
        }
        return N+1;
    }
};

int main(void) {
	vector<int> nums = { 7,8,9,11,12 };
    Solution sol;
    int a;
    a = sol.firstMissingPositive(nums);
    cout << a;
	return 0;
}
