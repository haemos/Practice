## 题目
在有向图中, 我们从某个节点和每个转向处开始, 沿着图的有向边走。 如果我们到达的节点是终点 (即它没有连出的有向边), 我们停止。

现在, 如果我们最后能走到终点，那么我们的起始节点是最终安全的。 更具体地说, 存在一个自然数 K,  无论选择从哪里开始行走, 我们走了不到 K 步后必能停止在一个终点。

哪些节点最终是安全的？ 结果返回一个有序的数组。

该有向图有 N 个节点，标签为 0, 1, ..., N-1, 其中 N 是 graph 的节点数.  图以以下的形式给出: graph[i] 是节点 j 的一个列表，满足 (i, j) 是图的一条有向边。

示例：

输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]

输出：[2,4,5,6]


## 思路
首先保存中每一个节点的出度，当一个结点的出度为0自然而然是安全得，然后由于将图反向，当一个结点删除后 把他所有原来可以到这个结点的结点度减1.直到又有出度为0结点。

## 代码
~~~ c++
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> degree(N,0);      // 存放度数。
        vector<vector<int>>rev(N,vector<int>(0));       // 注意题目中：graph[i] 是节点 j 的一个列表，满足 (i, j) 是图的一条有向边。
        for(int i=0;i<N;i++){
            degree[i]=graph[i].size();
            for(auto j:graph[i])            //反向
                rev[j].emplace_back(i);
        }
        queue<int> q;
        for(int i=0;i<N;i++)
            if(degree[i]==0)q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int p=q.front();
            q.pop();
            ans.push_back(p);
            for(int i=0;i<rev[p].size();i++){
                int y=rev[p][i];
                degree[y]--;
                if(degree[y]==0)
                    q.push(y);
            }
        }
        sort(ans.begin(),ans.end()); //题目要求结点按从小到大排序。
        return ans;
    }
};
~~~
