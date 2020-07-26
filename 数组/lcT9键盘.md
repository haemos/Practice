### 题目 
有图<https://leetcode-cn.com/problems/t9-lcci/>

###核心代码解析
~~~ c++
class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<char> mp = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
        int n1 = num.size(), i;
        vector<string> ans;
        for (string& w : words) {
            for (i = 0; i < n1; ++i) if (mp[w[i] - 'a'] != num[i]) break;
            if (i == n1) ans.emplace_back(w);
        }
        return ans;
    }
};
~~~
~~~ c++
vector<char> mp = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
~~~
将键盘abc---字母一一对应成数组，方便与输入数字进行对比。

~~~ c++
for (string& w : words) {
~~~
在words里取值给到w

~~~ c++
 for (i = 0; i < n1; ++i) if (mp[w[i] - 'a'] != num[i]) break;
 ~~~
w[i]对应一个字母减去'a’则可以得到和a得差，然后索引得到对应的建和num[i]进行比较。

~~~ c++
if (i == n1) ans.emplace_back(w);
~~~
当i=n1则是遍历完了一个单词发现都有。则将单词加入ans容器。

### 总代码
~~~ c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<char> mp = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
        int n1 = num.size(), i;
        vector<string> ans;
        for (string& w : words) {
            for (i = 0; i < n1; ++i) if (mp[w[i] - 'a'] != num[i]) break;
            if (i == n1) ans.emplace_back(w);
        }
        return ans;
    }
};


int main(void) {
	vector<string> words = { "tree", "used" };
    Solution sol;
    vector<string> a;
    string nums;
    cin >> nums;
    a = sol.getValidT9Words(nums,words);
    for (auto i = words.begin(); i != words.end(); i++)
        cout << *i;
	return 0;
}
~~~
