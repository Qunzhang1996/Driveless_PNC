#include<iostream>
#include <string>
using namespace std;

class Building
{
	friend void goodGay(Building* building);//��Ԫ���Է���˽�б���
public:
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SittingRoom;//seeting room
private:
	string m_BedRoom;//bedroom
};
//ȫ�ֺ���
void goodGay(Building *building)
{	
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << building->m_BedRoom << endl;
}
void test01() {
	Building building;
	goodGay(&building);
}
int main(){
	test01();
	system("pause");
	return 0;
}