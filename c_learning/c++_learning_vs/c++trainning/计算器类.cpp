#include<iostream>
using namespace std;
#include<string>
//分别使用普通写法和多态来实现计算器
//普通写法
class Calculator
{
public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_Num1 + m_Num1;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
	}
	
			
	int m_Num1;//操作数1
	int m_Num2;//操作数2
};
void test01()
{
	//创建计算器对象
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}
//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法计算器类
class AddCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1+m_Num2;
	}
};
//减法计算器类
class minusCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class timeCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1 * m_Num2;
	}
};
//除法计算器类
class divideCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1 / m_Num2;
	}
};
void test02()
{
	AbstractCalculator *abc = new AddCalculatir;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}