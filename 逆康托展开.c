/* 逆康托展开原理
	给定，字符个数 4，字典序序号 10，首先字典序 - 1 得到排在该字典序前的全排列个数，然后：
	9 / 3! 结果，商 1 余 3，说明首位要余出一个给 当前没用过的，最小的一个字符，因为它们占据了前 6 个排序。这里 “1” 没有用过，又是最小的字符，因此，我们应当使用 “2” 作为首位，并标记其已经使用。取余数进行下一步操作。
	3 / 2! 结果，商 1 余 1，说明第二位要余出一个给 当前没用过的，最小的字符。这里 “1” 没有用过，“2” 已经用了。因此，我们应当使用 “3” 作第二位。
	1 / 1! 结果，商 1 余 0，说明第三位要余出一个给 当前没用过的，最小的字符。这里 “1” 没有用过，“2” 已经用了，“3”也用了。因此，我们应当使用 “4” 作第三位。
	同康托展开，最后一位无需判断，所有字符中至今未使用的填入即可。
*/ 

#include<stdio.h>
#define Max 4
const int fact[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };//给出10以内的阶乘 

void revContor(int a[] , int rank) {
	int value, i,flag = 0;;
	int b[Max+1];
	rank -= 1;
	for (i = 1; i<Max; i++) {
		value = rank / fact[Max - i];
		rank = rank % fact[Max - i];
		flag = value + 1;
		for (value = 1; value <= Max; value++) {
			if (a[value] != 0)
				flag--;
			if (flag == 0)
				break;
		}
		b[i] = a[value] ;
		a[value] = 0;
	}
	for (value = 1; value <= Max; value++) {
		if (a[value] != 0) {
			b[i] = a[value];
			for (i = 1; i <= Max; i++) {
				printf("%5d", b[i]);
			}
			return ;
		}
	}
}


int main(void) {
	int i;
	int  arrange[Max + 1]; //先定义一个四以内排列,并且忽略0位 
	int  rank = 0;  //排列的序号；

	for (i = 0; i <= Max; i++) {
		arrange[i] = i;
	}
	scanf("%d", &rank);
	revContor(arrange, rank);
	
	return 0;
}
