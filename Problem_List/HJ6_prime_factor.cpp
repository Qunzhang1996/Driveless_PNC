/*
功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）
*/


#include <iostream>
using namespace std;
#include <cmath>

void calculate_prime_factors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "请输入一个大于0的正整数。" << endl;
        return 1;
    }

    calculate_prime_factors(n);
    cout << endl;

    return 0;
}
