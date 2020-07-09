/*编写程序，实现如下表所示的5-魔方阵。
17	24	1	8	15    所谓“n - 魔方阵”，指的是使用1〜n2共n2个自然数排列成一个n×n的方
23	5	7	14	16    阵，其中n为奇数；该方阵的每行、每列及对角线元素之和都相等，并为一
4	6	13	20	22    个只与n有关的常数，该常数为n×(n2 + 1) / 2。
10	12	19	21	3
11	18	25	2	9			
5 - 魔方阵		*/	

/*思路：
假定阵列的行列下标都从0开始，则魔方阵的生成方法为：在第0行中间置1，对从2开始的其余n2-1个数依次按下列规则存放：
(1) 假定当前数的下标为(i，j)，则下一个数的放置位置为当前位置的右上方，即下标为(i-1，j+1)的位置。
(2) 如果当前数在第0行，即i-1小于0，则将下一个数放在最后一行的下一列上，即下标为(n-1，j+1)的位置。
(3) 如果当前数在最后一列上，即j+1大于n-1，则将下一个数放在上一行的第一列上，即下标为(i-1，0)的位置。
(4) 如果当前数是n的倍数，则将下一个数直接放在当前位置的正下方，即下标为(i+1，j）的位置。

代码：
我的简单思路复现*/
#include <stdio.h>
#define Max 5

char num[Max][Max] = { 0 };

void nextxy(int* x, int* y, int value) {
	
	num[*x][*y] = value;

	if (value % 5 == 0) {
		if (*x < Max)
			*x = *x + 1;
		else
			*x = 0;
		return;
	}
	else {
		if (*x == 0)
		{
			*x = Max - 1;
			if (*y + 1 < Max)
				*y = *y + 1;
			else
				*y = 0;
			return;
		}
		else if (*y == Max - 1) {
			*y = 0;
			if (*x - 1 >= 0)
				*x = *x - 1;
			else
				*x = Max - 1;
			return;
		}
		else {
			*x = *x - 1;
			*y = *y + 1;
			return;
		}
	}
}

int main(void) {
	int i;
	int x = 0, y = 2;
	for (i = 1; i <= 25; i++) {
		nextxy(&x, &y, i);
	}

	for (i = 0; i <Max; i++) {
		for (int j = 0; j <Max; j++)
		{
			printf("%-5d",num[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*答案实现：*/
#include<stdio.h>
#include<stdlib.h>
int array(int n)
{
    int i, j, no, num, max;
    int *mtrx;
    if(n%2 == 0)  /*n是偶数，则加1使其变为奇数*/
    {
        n=n+1;
    }
    max=n*n;
    mtrx=(int *)malloc(max+max);  /*为魔方阵分配内存*/
    mtrx[n/2]=1;  /* 将1存入数组*/
    i=0;  /*自然数1所在行*/
    j=n/2;  /*自然数1所在列*/
    /*从2开始确定每个数的存放位置*/
    for(num=2; num<=max; num++)
    {
        i=i-1;
        j=j+1;
        if((num-1)%n == 0)  /*当前数是n的倍数*/
        {
            i=i+2;
            j=j-1;
        }
        if(i<0)  /*当前数在第0行*/
        {
            i=n-1;
        }
        if(j>n-1)  /*当前数在最后一列，即n-1列*/
        {
            j=0;
        }
        no=i*n+j;  /*找到当前数在数组中的存放位置*/
        mtrx[no]=num;
    }
    /*打印生成的魔方阵*/
    printf("生成的%d-魔方阵为:",n);
    no=0;
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n; j++)
        {
            printf("%3d", mtrx[no]);
            no++;
        }
    }
    printf("\n");
    free(mtrx);
    return 0;
}
int main()
{
    int n;
    printf("请输入n值:\n");
    scanf("%d", &n);
    array(n);  /*调用array函数*/
    return 0;
}
	
