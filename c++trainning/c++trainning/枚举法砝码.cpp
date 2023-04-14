/*砝码称重
[问题描述]
设有1g、2g、3g、5g、10g、20g的砝码各若干枚(其总重 <= 1000)求用这些砝码能称出不同的重量的个数。
[输入文件]
输入1g、2g、3g、5g、10g、20g的砝码个数[输出文件]
能称出不同的重量的个数[输入样例]
11000*/
#include<iostream>
using namespace std;
int flag[1005] = { 0 };

int main() {
	int n1, n2, n3, n5, n10, n20;
	cin >> n1 >> n2 >> n3 >> n5 >> n10 >> n20;
	//枚举不同法码的个数，计算总重量，并将总重量对应的标志置为1
	for (int i1 = 0; i1 <= n1; i1++) {
		for (int i2 = 0; i2 <= n2; i2++) {
			for (int i3 = 0; i3 <= n3; i3++) {
				for (int i5 = 0; i5 <= n5; i5++) {
					for (int i10 = 0; i10 <= n10; i10++) {
						for (int i20 = 0; i20 <= n20; i20++) {
							int sum = i1 + i2 * 2 + i3 * 3 + i5 * 5 + i10 * 10 + i20 * 20;
							flag[sum] = 1;
						}
					}
				}
			}
		}
	}
	//根据标志，计算总重量的个数
	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		if (flag[i]) count++;
	}
	cout << count << endl;
	return 0;
}
