#include<iostream>
using namespace std;
//�̳з�ʽ
//�����̳�
//˽�м̳�
//�����̳�
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1 :public Base1
{
public:
	void func()
	{
		m_A=10; //�ɷ��� publicȨ��
		m_B=100; //�ɷ��� protectedȨ��
		//m_C; //���ɷ���
	}
};

int main() {

	system("pause");
	return 0;
}
