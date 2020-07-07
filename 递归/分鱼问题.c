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
