/* 甲、乙、丙三位渔夫出海打鱼，他们随船带了21只箩筐。当晚返航时，他们发现有7筐装满了鱼，还有7筐装了半筐鱼，另外7筐则是空的，由于他们没有秤，只好通过目测认为7个满筐鱼的重量是相等的，
7个半筐鱼的重量是相等的。在不将鱼倒出来的前提下,怎样将鱼平分为3份？*/

#include<iostream>

int fish[3][3] = { 0 };  //每一行代表一个人，列分别代表满筐数，半筐数，和空筐数。
int full = 7;
int half = 7;
int empty = 7;

void print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <=2; j++) {
			switch (j) {
				case 0:
					std::cout << "满筐数为：";
					break;
				case 1:
					std::cout << "半筐数为：";
					break;
				case 2 :
					std::cout << "空筐数为：";
					break;
			}
			std::cout << fish[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int fishSharing(int k) {	
	int full1, half1, empty1;
	full1 = full;
	half1 = half;
	empty1 = empty;
	
	if (full < 0 || half < 0 || empty < 0)
		return 0;

	for (int i = 0; i < 3; i++) {
		if (fish[i][0] + 0.5*fish[i][1]> 3.5)
			return 0;
	}
	if (!full && !half && !empty)
		return 1;
	for (int i = 1; i <= 3; i++) {
		fish[k][0] = i;
		full -= i;
		fish[k][1]=(3.5-i)/(0.5);
		half = half - fish[k][1];
		fish[k][2] = 7 - fish[k][0] - fish[k][1];
		empty = empty - fish[k][2];
		if (fishSharing(k + 1)) {
			print();
		}
		full = full1;		//恢复上一次各种框框数。
		half = half1;		
		empty = empty1;
	}
	return 0;

}

int main(void) {	
	

	std::cout << "The solution of this question is" << std::endl;
	fishSharing(0);
	return 0;
}
