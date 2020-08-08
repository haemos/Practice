### 题目
给你一个大小为 m * n 的方阵 mat，方阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回方阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

### 代码
~~~ c++
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> power;
        for (int i = 0; i < n; ++i) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            power.emplace_back(sum, i);
        }
        sort(power.begin(), power.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(power[i].second);
        }
        return ans;
    }
};
~~~
