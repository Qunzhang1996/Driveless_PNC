#include<iostream>
using namespace std;
//f[i][j] i 数量 j总重量
int f[1005][1005] = { 0 };
int main() {
	//1.统计砝码总数，准备好砝码序列
	int num = 0;//砝码总数
	int w[1005];//砝码序列
	int a[7] = { 0,1,2,3,5,10,20 };
	for (int i = 1; i <= 6; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) w[++num] = a[i];
	//2.初始化动态规划数组，做动态规划
		for (int i = 0; i <= 1000; i++) f[i][0] = 1;
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= 1000; j++) {
				if (j - w[i] >= 0)
					f[i][j] = f[i - 1][j] || f[i - 1][j - w[i]];
				else
					f[i][j] = f[i - 1][j];
			}
		}
	}
	//3.统计方案总数
	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		if (f[num][i]) count++;
	}
	cout << count << endl;
	return 0;
}