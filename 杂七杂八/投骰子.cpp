/*骰子是一个有六个面的正方体，每个面分别印有1〜6之间的小圆点代表点数。假设这个游戏的规则是：两个人轮流掷骰子6次
，并将每次投掷的点数累加起来。点数多者获胜；点数相同则为平局。要求编写程序模拟这个游戏的过程，并求出玩100盘之后
谁是最终的获胜者。*/

#include<iostream>
#include<stdlib.h>
#include<time.h>


int main(void) {
	int sum1, sum2,flag1,flag2;
	
	flag1 = flag2 = 0;
	srand((unsigned)time(NULL));
	rand();
	for (int i = 1; i < 100; i++) {
		sum1 = sum2 = 0;
		for (int j = 1; j <= 6; j++) {
			sum1 = sum1 + rand() % 6 + 1;
			sum2 = sum2 + rand() % 6 + 1;
		}
		sum1 > sum2 ? flag1++ : flag2++;
				
	}

	if (flag1 > flag2)
		std::cout << "The first win\n";
	else
		std::cout << "The second win\n";

	return 0;
}