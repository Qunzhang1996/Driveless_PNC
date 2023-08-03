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
		cout << "��ũ��ɽȪ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�����ȵ��뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "����ţ��!" << endl;
	}
};
//������ˮ
class Tea : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "������ˮ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "����ˮ���뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "�������!" << endl;
	}
};
//��������
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