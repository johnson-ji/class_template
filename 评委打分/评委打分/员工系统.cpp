#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

# define CEHUA 0
# define MEISHU 1
# define YANFA 2

/*
* ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
* Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
* �����10��Ա�����䲿�ź͹���
* ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
* �ֲ�����ʾԱ����Ϣ
*/

class employee
{
public:
	string m_name;
	int m_salary;
};

void set_v(vector<employee>& v)
{
	for (int i = 0; i < 10; i++)
	{
		string nameseed = "ABCDEFGHIJ";
		employee worker;
		worker.m_name = "employee ";
		worker.m_name = +nameseed[i];

		worker.m_salary = rand() % 10000 + 10000;

		int dep = rand() % 3;
		v.push_back(worker);
	}
}

void set_dep(vector<employee>& v, multimap<int, employee>& m)
{
	for (vector<employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		int dep = rand() % 3;
		m.insert(make_pair(dep, *it));
	}
}

void show_worker(multimap<int, employee>& m)
{

	cout << "�߻����ţ�" << endl;
	map<int, employee>::iterator ret = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; ret != m.end() && index < count; index++, ret++)
	{
		cout << "name: " << (*ret).second.m_name << " salary: " << (*ret).second.m_salary << endl;
	}

	cout << "============================" << endl;
	cout << "�������ţ�" << endl;
	ret = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; ret != m.end() && index < count; index++, ret++)
	{
		cout << "name: " << (*ret).second.m_name << " salary: " << (*ret).second.m_salary << endl;
	}

	cout << "============================" << endl;
	cout << "�з����ţ�" << endl;
	ret = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; ret != m.end() && index < count; index++, ret++)
	{
		cout << "name: " << (*ret).second.m_name << " salary: " << (*ret).second.m_salary << endl;
	}
}

int main()
{
	//put the employee into vector.
	vector <employee> v_emp;
	set_v(v_emp);

	//test.
	//for (vector<employee>::iterator it = v_emp.begin(); it != v_emp.end(); it++)
	//{
	//	cout << "name: " << (*it).m_name << " salary: " << (*it).m_salary << endl;
	//}

	//set department.
	multimap<int, employee> company;
	set_dep(v_emp,company);

	//show workers.
	show_worker(company);

	system("pause");
	return 0;

}



