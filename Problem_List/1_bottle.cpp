// #include <iostream>
// using namespace std;

// int getDrinks(int n) {
//     // If n is less than 2, we can't get any more drinks.
//     if (n < 2)
//         return 0;

//     // Number of drinks you can get initially.
//     int drinks = n / 3;

//     // Remaining bottles after exchanging for drinks.
//     int remain = n % 3;

//     // If we have 2 bottles remaining, borrow 1 bottle from the boss, get another drink and return the empty bottle.
//     if (remain == 2) {
//         drinks += 1; // Get one more drink
//         remain = 1;  // Return 1 empty bottle, not 0
//     }

//     // Recursively find out how many more drinks you can get.
//     return drinks + getDrinks(drinks + remain);
// }

// int main() {
//     int n;
//     while (true) {
//         cin >> n;
//         if (n == 0) {
//             break;
//         }
//         cout << getDrinks(n) << endl;
//     }
//     return 0;
// }
/*
某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
数据范围：输入的正整数满足 1≤n≤100 

注意：本题存在多组输入。输入的 0 表示输入结束，并不用输出结果
*/
#include <iostream>
using namespace std;

int maxSodas(int bottles) {
    // 当手上只有1个或者没有瓶子的时候，不能再换汽水了
    if (bottles < 2) {
        return 0;
    }
    // 当手上有2个瓶子的时候，可以借一个瓶子换一瓶汽水，然后把借的瓶子还掉
    else if (bottles == 2) {
        return 1;
    }
    // 当手上有3个及以上瓶子的时候，可以直接换汽水，并且剩下的瓶子继续换
    else {
        return bottles / 3 + maxSodas(bottles / 3 + bottles % 3);
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << maxSodas(n) << endl;
    }
    return 0;
}
