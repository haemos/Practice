#include<iostream>

const unsigned int Max = 8;
void solution(int a[],int k, int threshold) {
	int i, sum=0,flag=0;
	for (i = 0; i < Max; i++) {
		if (a[i] + a[i+1] + a[i+2] - k * threshold >= 0)
		{
			sum += 1;
		}
	}
	std::cout << sum;
	return;
}

int main(void) {
	int array[Max] = { 2,2,2,2,5,5,5,8 };
	int k = 3;
	int threshold = 4;

	solution(array, k, threshold);
	return 0;
}
