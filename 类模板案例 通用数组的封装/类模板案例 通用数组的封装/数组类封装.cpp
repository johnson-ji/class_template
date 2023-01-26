#include <iostream>
#include<string>
#include"my_arr.hpp"
using namespace std;

class Person {
public:
	Person() {}
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};


void printarr(my_arr<int>& arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << arr[i] << " ";
	}
}

void test01()
{
	my_arr<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.push_back(i);
	}

	printarr(arr1);
	cout << "len: " << arr1.get_len() << endl;
	cout << "size: " << arr1.get_size() << endl;

	my_arr<int>arr2(arr1);
	arr2.pop_back();
	printarr(arr2);
	cout << "len: " << arr2 .get_len() << endl;
	cout << "size: " << arr2.get_size() << endl;
}

void printPersonArray(my_arr<Person>& personArr)
{
	for (int i = 0; i < personArr.get_size(); i++) {
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}

}

void test02()
{
	my_arr<Person> parr(10);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	//��������
	parr.push_back(p1);
	parr.push_back(p2);
	parr.push_back(p3);
	parr.push_back(p4);
	parr.push_back(p5);

	printPersonArray(parr);

	cout << "pArray��������" << parr.get_len() << endl;
	cout << "pArray�Ĵ�С��" << parr.get_size() << endl;
	
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
