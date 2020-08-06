### 题目
一个已排序好的表 A，其包含 1 和其他一些素数.  当列表中的每一个 p<q 时，我们可以构造一个分数 p/q 。

那么第 k 个最小的分数是多少呢?  以整数数组的形式返回你的答案, 这里 answer[0] = p 且 answer[1] = q.

示例:
输入: A = [1, 2, 3, 5], K = 3
输出: [2, 5]
解释:
已构造好的分数,排序后如下所示:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
很明显第三个最小的分数是 2/5.

输入: A = [1, 7], K = 1
输出: [1, 7]

### 代码与思路解析
~~~ C++
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        int n = A.size();
        double l = 0.0;
        double r = 1.0;
        while(l < r){
            double mid = (l + r) / 2.0;
            int sum = 0;
            vector<int> res = {0 , 1};
            int j = 0;
            for(int i = 0 ; i<n ; ++i){               
                while(j < n && A[i] >= mid * A[j]){       //算出此时比mid小分数有多少个。
                    ++j;
                }
                sum += n - j;
                //cout<<sum<<endl;
                if(j < n && res[0] * A[j] < res[1] * A[i]){         // 这个式子实际上是res[0]/res[1]<res[i]/res[j] 变形而来。当此时的分数大于时就替换它。
                    res = {A[i] , A[j]};
                }
            }
            //cout<<sum<<endl;
            if(sum == k){                 
                return res;
            }
            else if(sum < k){         // 当此时比mid小分数数量小于要的K时，
                l = mid;
            }
            else r = mid;
        }
        return {};
    }
};
~~~
