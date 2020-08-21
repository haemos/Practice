/*A、B、C、D、E这5个人合伙夜间捕鱼，凌晨时都已经疲惫不堪，于是各自在河边的树丛中找地方睡着了。第二天日上三竿时，A第一个醒来，他将鱼平分为5份，把多余的一条扔回河中，然后拿着自己的一份回家去了；
B第二个醒来，但不知道A已经拿走了一份鱼，于是他将剩下的鱼平分为5份，扔掉多余的一条，然后只拿走了自己的一份；接着C、D、E依次醒来，也都按同样的办法分鱼。问这5人至少合伙捕到多少条鱼？每个人醒来
后所看到的鱼是多少条？*/

#include <stdio.h>

int fishSharing(int num,int fishs){
	if((fishs-1)%5==0){
		if(num == 1)
			return 1;		//返回值来判断递归结束出循环。 
		else
			return fishSharing(num-1,4*(fishs-1)/5);	//递归走分鱼问题。 
	}
	return 0;
}

int main(void){
	int fishs = 6;	//9以下明显不可能 虽然9也不可能。 
	int flag = 0;
	while(!flag){
		flag = fishSharing(5,fishs);
		if(flag){
			printf("%d",fishs);
			break;	
		}
		fishs+=5;	
	}
	return 0;
} 
