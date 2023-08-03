#include<iostream>
using namespace std;
//继承方式
//公共继承
//私有继承
//保护继承
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
		m_A=10; //可访问 public权限
		m_B=100; //可访问 protected权限
		//m_C; //不可访问
	}
};

int main() {

	system("pause");
	return 0;
}
