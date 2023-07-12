#include<iostream>
using namespace std;
class AbstractDrinking
{
public:
	//Boil
	virtual void Boil() = 0;
	//brew
	virtual void Brew() = 0;
	//pour
	virtual void PourInCup() = 0;
	//put something
	virtual void PutSomething() = 0;
	//make drink
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
class Coffee :public AbstractDrinking
{
public:
	virtual void Boil() {
		cout << "煮农夫山泉!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将咖啡倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入牛奶!" << endl;
	}
};
//制作茶水
class Tea : public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "煮自来水!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将茶水倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入枸杞!" << endl;
	}
};
//制作函数
//void doWork(AbstractDrinking* abs)
//{
//	abs->makeDrink();
//};
//void test01()
//{	
//	doWork(new Coffee);
//}
void test01() {
	AbstractDrinking* abs = new Coffee;
	abs->makeDrink();
	delete abs;
}
int main() {
	test01();
	system("pause");
	return 0;
}