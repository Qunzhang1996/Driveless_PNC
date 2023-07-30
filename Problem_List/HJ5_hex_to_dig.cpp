/*
输入一个十六进制的数值字符串。
*/
#include <iostream>

int main() {
    unsigned int number;
    scanf("%x", &number);  // 读取十六进制数，%x格式化输入可以处理带有0x或0X前缀的数
    printf("%u\n", number);  // 输出十进制表示
    return 0;
}
