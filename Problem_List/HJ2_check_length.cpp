
/*
计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
输入描述：
输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。
*/

#include <iostream>
#include <string>
using namespace std;

int LastWordLength(const string& input) {
    int len = input.length();
    int lastWordLength = 0;
    
    // 从字符串末尾开始向前遍历
    int i = len - 1;
    while (i >= 0 && input[i] == ' ') {
        // 跳过末尾的空格
        i--;
    }
    
    while (i >= 0 && input[i] != ' ') {
        // 统计最后一个单词的长度
        lastWordLength++;
        i--;
    }
    
    return lastWordLength;
}

int main() {
    string input;
    getline(cin, input); // 使用getline读取整行输入

    int length = LastWordLength(input);
    cout << length << endl;

    return 0;
}
