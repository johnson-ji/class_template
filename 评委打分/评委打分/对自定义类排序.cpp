#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;

class person
{
public:
	person(string name, int age, int height)
	{
		m_age = age;
		m_height = height;
		m_name = name;
	}

	int m_age;
	int m_height;
	string m_name;

};

bool rule(person& p1, person& p2)
{
	if (p1.m_age == p2.m_age)
	{ 
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
	
}

int main3()
{
	list<person> L;

	person p1("Áõ±¸", 35, 175);
	person p2("²Ü²Ù", 45, 180);
	person p3("ËïÈ¨", 40, 170);
	person p4("ÕÔÔÆ", 25, 190);
	person p5("ÕÅ·É", 35, 160);
	person p6("¹ØÓğ", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name: " << (*it).m_name << "  age: " << (*it).m_age << "  height: " << (*it).m_height << endl;
	}

	//sort it
	cout << "after sort" << endl;

	L.sort(rule);
	for (list<person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name: " << (*it).m_name << "  age: " << (*it).m_age << "  height: " << (*it).m_height << endl;
	}

	
	system("pause");
	return 0;

}



