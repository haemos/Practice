#include<stdio.h>

int judge(int x,int y,int x1,int y1){
	if(x == x1){
		if(y>y1)
			return 3;	//下 
		else
			return 4;	//上 
	}
	if(x>x1)
		return 1;		//右 
	else
		return 2;		//左 
}

int main(){
    int x,y,x1,y1,sign;
    
    printf("第一个坐标\n"); 
    scanf("%d %d",&x,&y);
    printf("第二个坐标\n"); 
    scanf("%d %d",&x,&y);
    sign = judge(x,y,x1,y1);
    if(sign==1){
    	printf("第三个坐标\n"); 
   		scanf("%d %d",&x,&y);
    	sign = judge(x1,y1,x,y);  //二三坐标判断。
		if(sign == 3)
			printf("顺时针。");
		else
			printf("逆时针。"); 
	}else if(sign == 2){
		printf("第三个坐标\n"); 
   		scanf("%d %d",&x,&y);
    	sign = judge(x1,y1,x,y);  //二三坐标判断。
		if(sign == 4)
			printf("顺时针。");
		else
			printf("逆时针。");
	}else if(sign == 3){
		printf("第三个坐标\n"); 
   		scanf("%d %d",&x,&y);
    	sign = judge(x1,y1,x,y);  //二三坐标判断。
		if(sign == 2)
			printf("顺时针。");
		else
			printf("逆时针。");
	}else if(sign == 4){
		printf("第三个坐标\n"); 
   		scanf("%d %d",&x,&y);
    	sign = judge(x1,y1,x,y);  //二三坐标判断。
		if(sign == 1)
			printf("顺时针。");
		else
			printf("逆时针。");
	}
	
	return 0;
}
