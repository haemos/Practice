### 题目
有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。

paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。

另外，没有花园有 3 条以上的路径可以进入或者离开。

你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。

### 思路
遍历花园 每一个花园验证他的邻接点。

### code
~~~ c++
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> datas(N);
        vector<int> res(N,0);
        for(int i = 0; i < paths.size(); i++){              //构建邻接表
            datas[paths[i][0]-1].push_back(paths[i][1]-1);     //给每个花园后面加上邻接的花园
            datas[paths[i][1]-1].push_back(paths[i][0]-1);     //和上一句一样 不过是反过来也在邻接。
        }
        for(int i = 0; i < N; i++){
            int m[4] = {0};           //存放花色
            for(int j = 0; j < datas[i].size(); j++){
                if(res[datas[i][j]] != 0){      
                    m[res[datas[i][j]]-1]++;    //用过的花色变为1
                }
            }

            for(int j = 0; j < 4; j++){
                if(m[j] == 0 ){             // 遍历将没有用过的花色添加进res     
                    res[i] = j + 1;
                    break;
                }
            }
        }
        
        return res;       返回res
    }
        
}；
~~~
