### 题目  
  设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
"X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tic-tac-toe-lcci

### code  时间超97.96 空间100 perSolu。
~~~ c++
#include <iostream>
#include <vector>
using namespace std;

class solution {
public :
	string tictactoe(vector<string>& board) {
        int N = board.size();
        int sum, sumxy,sumy,sumyx;
        sum = sumxy = sumyx = sumy = 0;
        bool is_full = true;
        int k = N-1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == ' ')
                    is_full = false;
                sum += board[i][j];
                if (i == 0) {       //算对角线只算一次节省时间
                    sumxy += board[j][j];
                    if (k >= 0)           //另一个对角线。
                        sumyx += board[j][k--];
                }
                sumy += board[j][i];    //竖直方向
            }
            if (sum == N * 88 || sumxy == N*88 || sumyx == N*88 || sumy == N*88) {   //   X ASCII 88 O 79
                return "X";
            }
            if (sum == N * 79 || sumxy == N * 79 || sumyx == N * 79 || sumy == N * 79) {
                return "O";
            }
            sum = sumy = 0 ;
        }
        if (is_full)return "Draw";
        
        return "Pending";
	}
};

int main(void) {
	  vector<string> board{ "X" };
    string a;
    solution sol;
    a = sol.tictactoe(board);
    cout << a;
	  return 0;
}
~~~

### 他人做法 时间超97.74 空间100 分析。
~~~ c++
       bool is_full = true;
        bool XDiaWin = false, ODiaWin = false;
        bool XiDiaWin = false, OiDiaWin = false;
        for(int i=0;i<N;++i)
        {
            bool XRowWin = false, XColWin = false;
            bool ORowWin = false, OColWin = false;
            for(int j=0;j<N;++j)
            {
                if(is_full && board[i][j] == ' ')
                {
                    is_full = false;
                }
                if(!XRowWin) XRowWin = XRowWin || ('X' ^ board[i][j]);          // 核心思路  ^相同为0 不同为1，只要一直 X 则一直false,O也类推。前两行判断X0横向 后两行判断竖向。为1了
                if(!ORowWin) ORowWin = ORowWin || ('O' ^ board[i][j]);          // 则由于 || 一直为1.
                if(!XColWin) XColWin = XColWin || ('X' ^ board[j][i]);
                if(!OColWin) OColWin = OColWin || ('O' ^ board[j][i]);
            }
            if(!XRowWin || !XColWin) return "X";          //遍历完后只有有false就有一方赢。
            if(!ORowWin || !OColWin) return "O";
            // diagonal
            if(!XDiaWin) XDiaWin = XDiaWin || ('X' ^ board[i][i]);            // 一样判断方法 来判断对角线。
            if(!ODiaWin) ODiaWin = ODiaWin || ('O' ^ board[i][i]);
            if(!XiDiaWin) XiDiaWin = XiDiaWin || ('X' ^ board[i][N-1-i]);
            if(!OiDiaWin) OiDiaWin = OiDiaWin || ('O' ^ board[i][N-1-i]);
        }
        if(!XDiaWin || !XiDiaWin) return "X";
        if(!ODiaWin || !OiDiaWin) return "O";
        if(is_full) return "Draw";
        return "Pending";
    }
};
~~~
作者：eason-lee-2
链接：https://leetcode-cn.com/problems/tic-tac-toe-lcci/solution/wei-yun-suan-shi-jian-da-bai-9774kong-jian-da-bai-/
来源：力扣（LeetCode）


