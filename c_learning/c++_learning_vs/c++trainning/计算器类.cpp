#include<iostream>
using namespace std;
#include<string>
//�ֱ�ʹ����ͨд���Ͷ�̬��ʵ�ּ�����
//��ͨд��
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
	
			
	int m_Num1;//������1
	int m_Num2;//������2
};
void test01()
{
	//��������������
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}
//���ö�̬ʵ�ּ�����
//ʵ�ּ�����������
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//�ӷ���������
class AddCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1+m_Num2;
	}
};
//������������
class minusCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1 - m_Num2;
	}
};
//�˷���������
class timeCalculatir :public AbstractCalculator {
public:
	virtual int getResult() {
		return m_Num1 * m_Num2;
	}
};
//������������
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