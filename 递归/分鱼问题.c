#include <stdio.h>

int fishSharing(int num,int fishs){
	if((fishs-1)%5==0){
		if(num == 1)
			return 1;		//����ֵ���жϵݹ������ѭ���� 
		else
			return fishSharing(num-1,4*(fishs-1)/5);	//�ݹ��߷������⡣ 
	}
	return 0;
}

int main(void){
	int fishs = 6;	//9�������Բ����� ��Ȼ9Ҳ�����ܡ� 
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
