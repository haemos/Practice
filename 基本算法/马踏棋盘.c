//国际象棋的棋盘为8×8的方格棋盘。现将“马”放在任意指定的方格中，按照“马”走棋的规则将“马”进行移动。要求每个方格只能进入一次，最终使得“马”走遍棋盘的64个方格。

//编写一个C程序，实现马踏棋盘操作，要求用1〜64这64个数字标注马移动的路径，也就是按照求出的行走路线，将数字1，2，……64依次填入棋盘的方格中，并输出。

#include<stdio.h>
#define X 8
#define Y 8
int board[X][Y] = { 0 };


int nextxy(int* x, int* y, int sample) { //用地址更方便移动判断。
	switch (sample)
	{
		case 0:
			if (*x + 2 < X && *y - 1 >= 0 && board[*x+2][*y-1] == 0) {
				*x = *x + 2;
				*y = *y - 1;	//将传入的地址存放的值换位下一个的值起到更换坐标的作用。
                return 1;
			}
			break;
        case 1:
            if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && board[*x + 2][*y + 1] == 0)
            {
                *x = *x + 2;
                *y = *y + 1;
                return 1;
            }
            break;
        case 2:
            if (*x + 1 <= X - 1 && *y - 2 >= 0 && board[*x + 1][*y - 2] == 0)
            {
                *x = *x + 1;
                *y = *y - 2;
                return 1;
            }
            break;
        case 3:
            if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && board[*x + 1][*y + 2] == 0)
            {
                *x = *x + 1;
                *y = *y + 2;
                return 1;
            }
            break;
        case 4:
            if (*x - 2 >= 0 && *y - 1 >= 0 && board[*x - 2][*y - 1] == 0)
            {
                *x = *x - 2;
                *y = *y - 1;
                return 1;
            }
            break;
        case 5:
            if (*x - 2 >= 0 && *y + 1 <= Y - 1 && board[*x - 2][*y + 1] == 0)
            {
                *x = *x - 2;
                *y = *y + 1;
                return 1;
            }
            break;
        case 6:
            if (*x - 1 >= 0 && *y - 2 >= 0 && board[*x - 1][*y - 2] == 0)
            {
                *x = *x - 1;
                *y = *y - 2;
                return 1;
            }
            break;
        case 7:
            if (*x - 1 >= 0 && *y + 2 <= Y - 1 && board[*x - 1][*y + 2] == 0)
            {
                *x = *x - 1;
                *y = *y + 2;
                return 1;
            }
            break;
        default:
            break;
    }
    return 0;
}

int horseBoard(int x, int y, int count) {
	int flag = 0 , sample = 0;
	int x1 = x, y1 = y;
	board[x][y] = count;

	if (count == X * Y) {
		return 1;			//走遍了棋盘。
	}
    flag = nextxy(&x1, &y1, sample);
	while (flag == 0 && sample <=7) {
        sample += 1;
        flag = nextxy(&x1, &y1, sample); //遍历八种情况
	}
    while (flag) {
        if (horseBoard(x1, y1, count + 1))
            return 1;//排序完成后出函数。
        x1 = x;
        y1 = y;     //往上回一步选择另一条支路
        sample += 1;
        flag = nextxy(&x1, &y1, sample);           //寻找下一个可走支路。
        while (flag == 0 && sample < 7) {
            sample += 1;
            flag = nextxy(&x1, &y1, sample); //遍历八种情况。
        }
    }
    if (flag == 0) {
        board[x][y] = 0; //清零往上回溯。
        return 0;
    }
}

int main(void) {
	int i, j;
	
	if (horseBoard(2, 0, 1)) {          //马的初始位置。
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%-5d", board[i][j]);
			}
            printf("\n");
		}
	}
	else
		printf("The initial loaction can't travel the chess board\n");
	return 0;
}
